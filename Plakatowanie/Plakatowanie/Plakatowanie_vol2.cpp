#include <iostream>
#include <cstdint>
#include <vector>

struct Segment
{
	uint32_t Height;
	std::vector<Segment*> Above;
};

struct SegmentPool
{
	uint32_t Size;
	Segment* Buffer;

	Segment* Alloc(uint32_t height) noexcept { Buffer[Size].Height = height; return Buffer + Size++; }
};

void ProcessNewSegment(SegmentPool& pool, Segment* current, uint32_t height) noexcept
{
	if (current->Height == height)
	{
		// If more segments above, indicate hole
		if (current->Above.size() != 0 && current->Above.back() != nullptr)
			current->Above.emplace_back(nullptr);
	}
	else if (current->Height < height)
	{
		height -= current->Height;
		// Move forward in hierarchy
		if (current->Above.size() != 0 && current->Above.back() != nullptr)
			ProcessNewSegment(pool, current->Above.back(), height);
		else
		{
			// When top-most then just append new above
			current->Above.emplace_back(pool.Alloc(height));
		}
	}
	else
	{
		// Create new segment above current one
		Segment* newSeg = pool.Alloc(current->Height - height);
		newSeg->Above = std::move(current->Above);
		current->Height = height;

		// Append new segment above current one and indicate hole
		current->Above.emplace_back(newSeg);
		current->Above.emplace_back(nullptr);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	uint32_t size;
	std::cin >> size;

	// Will be more than enough, bulk alloc to avoid lot's of smaller ones
	SegmentPool pool = { 1, new Segment[size] };

	// Ignoring width
	std::cin >> pool.Buffer[0].Height >> pool.Buffer[0].Height;
	for (uint32_t i = 1; i < size; ++i)
	{
		uint32_t height;
		std::cin >> height >> height;
		ProcessNewSegment(pool, pool.Buffer, height);
	}

	std::cout << pool.Size;
	delete[] pool.Buffer;
	return 0;
}