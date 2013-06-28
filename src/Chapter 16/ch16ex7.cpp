#include "chapter16_exercises.h"

static std::vector<int> Lotto(const int p_NumberOfSpots, const int p_NumberOfSpotsSelectedAtRandom);

void ch16ex7(void)
{
	std::vector<int> winningNumbers = Lotto(55, 4);
	std::copy(winningNumbers.begin(), winningNumbers.end(), std::ostream_iterator<int>(std::cout, " "));
}

std::vector<int> Lotto(const int p_NumberOfSpots, const int p_NumberOfSpotsSelectedAtRandom)
{
	std::vector<int> possibleValues;
	for (int i = 1; i <= p_NumberOfSpots; ++i)
		possibleValues.push_back(i);

	std::random_shuffle(possibleValues.begin(), possibleValues.end());
	return std::vector<int>(possibleValues.begin(), possibleValues.begin()+p_NumberOfSpotsSelectedAtRandom);
}

