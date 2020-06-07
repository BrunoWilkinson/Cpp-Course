#include <iostream>

struct Advertising
{
	int adsShown;
	double clickThroughRatePercentage;
	double averageEarningsPerClick;
};

Advertising getAvertising()
{
	Advertising temp;
	std::cout << "How many ads were shown today? ";
	std::cin >> temp.adsShown;
	std::cout << "What percentage of ads were clicked by users? ";
	std::cin >> temp.clickThroughRatePercentage;
	std::cout << "What was the average earning per click ? ";
	std::cin >> temp.averageEarningsPerClick;
	return temp;
}

double calculateDailyEarn(Advertising ad)
{
	return (ad.adsShown * (ad.clickThroughRatePercentage / 100) * ad.averageEarningsPerClick);
}

void printCalculateAd(Advertising ad)
{
	std::cout << "Number of ads shown: " << ad.adsShown << "\n";
	std::cout << "Click throught rate: " << ad.clickThroughRatePercentage << "\n";
	std::cout << "Average earnings per clicks: $" << ad.averageEarningsPerClick << "\n";
	std::cout << "Earning today: $" << calculateDailyEarn(ad)  << "\n";
};

int main()
{
	Advertising todayAds { getAvertising() };
	printCalculateAd(todayAds);
	return 0;
}