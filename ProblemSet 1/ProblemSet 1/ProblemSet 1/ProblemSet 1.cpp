#include <string>
#include <iostream>
using namespace std;
#define ROW 4
#define COL 3

int main()
{
	int UnitSold[ROW][COL];
	string UnitName[4] = { "RS Pro with GPS" , "Transcend Drive Pro", "H203 1080P", "Pioneer" };
	std::string BranchName[3] = { "SJ Branch ", "PJ Branch", "KL Branch" };
	int Prices[4] = { 730, 850, 150, 350 };
	int GrossSale[3] = { 0,0,0 };
	string HighestBranchSale;
	int TotalUnitSold[4] = { 0,0,0,0 };
	string MostPopularDashCamUnit;
	cout << "Enter sales figures for each brand" << endl;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout << "Enter sales figure for " << UnitName[i] << " in " << BranchName[j] << " ";
			cin >> UnitSold[i][j];
			TotalUnitSold[i] += UnitSold[i][j];
			cout << endl;
		}
	}

	for (int k = 0; k < COL; k++)
	{
		for (int l = 0; l < ROW; l++)
		{

			UnitSold[l][k] *= Prices[l];
			GrossSale[k] += UnitSold[l][k];
		}
	}

	cout << endl;

	for (int o = 0; o < COL; o++)
	{
		cout << "Total gross sales for " << BranchName[o] << " is: RM " << GrossSale[o] << endl;
	}

	cout << endl;

	for (int v = 0; v < COL; v++)
	{
		if (GrossSale[0] <= GrossSale[v])
		{
			GrossSale[0] = GrossSale[v];
			HighestBranchSale = BranchName[v];
			TotalUnitSold[0] = TotalUnitSold[v];
			MostPopularDashCamUnit = UnitName[v];
		}
	}

	cout << endl << "The highest sales figure is RM " << GrossSale[0] << " By " << HighestBranchSale;
	cout << endl;
	cout << endl << "The most popular dash cam model is " << MostPopularDashCamUnit << "with unit sold of " << TotalUnitSold[0] << " units ";

	return 0;
}

