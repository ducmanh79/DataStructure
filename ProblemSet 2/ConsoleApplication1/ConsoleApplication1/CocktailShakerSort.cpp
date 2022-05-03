#include "IntVector.h";
#include "CocktailShakerSort.h";


void CocktailShakerSort::operator()(IntVector& aContainer) const {

	int Left = 0;
	int Right = aContainer.size() - 1;
	int k = 0;
	while (Left < Right)
	{
		for (int i = Left; i < Right; i++)
		{
			if (aContainer[i] > aContainer[i + 1])
			{
				aContainer.swap(i, i + 1);
				k = i;
			}
		}//sort left to right(maximum)
		Right = k;
		for (int i = Right; i > Left; i--)
		{
			if (aContainer[i] < aContainer[i - 1])
			{
				aContainer.swap(i, i - 1);
				k = i;
			}
		}//sort right to left(minimum)
		Left = k;
	}
}