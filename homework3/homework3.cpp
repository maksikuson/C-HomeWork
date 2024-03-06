#include <iostream>
using namespace std;

int main()
{

	//Task1

	/*	int distance, time, speed;
		cout << "Enter distance : ";
		cin >> distance;
		cout << "Enter time: ";
		cin >> time;
		speed = distance / time;
		cout << "Speed of movment : " << speed << endl; */

		//Task2

		/*		int start_hour, start_minute, start_second;
			int end_hour, end_minute, end_second;

			cout << "Enter the time to start using the scooter : ";
			cin >> start_hour >> start_minute >> start_second;

			cout << "Enter the time when the scooter ends : ";
			cin >> end_hour >> end_minute >> end_second;

			int start_time_seconds = start_hour * 3600 + start_minute * 60 + start_second;
			int end_time_seconds = end_hour * 3600 + end_minute * 60 + end_second;
			int duration_seconds = end_time_seconds - start_time_seconds;
			int cost_per_minute = 2;
			int total_cost = cost_per_minute * (duration_seconds + 59) /60;

			cout << "The cost of the trip : " << total_cost << " UAH" << endl; */

			//Task3

			/*	int distance, distribution_per_100km;
				int price1, price2, price3;

				cout << "Enter gasoline consumption per 100km : ";
				cin >> distance;

				cout << "Enter gasoline distribution per 100km : ";
				cin >> distribution_per_100km;

				cout << "Enter price for the 1st type of gasoline : ";
				cin >> price1;

				cout << "Enter price for the 2nd type of gasoline : ";
				cin >> price2;

				cout << "Enter price for the 3rd type of gasoline : ";
				cin >> price3;

				int distribution = distribution_per_100km * distance / 100;
				int cost1 = distribution * price1;
				int cost2 = distribution * price2;
				int cost3 = distribution * price3;

				cout << "Gasoline Type \t\t Cost" << endl;
				cout << "------------------------------------" << endl;
				cout << "1st Type \t\t " << cost1 << " UAH" << endl;
				cout << "2nd Type \t\t " << cost2 << " UAH" << endl;
				cout << "3rd Type \t\t " << cost3 << " UAH" << endl; */

				//Task4

				/*	int allTime = 86400;
					int leftTime;

					cout << "Enter the time passed since midnight : ";
					cin >> leftTime;

					int currentSec = allTime - leftTime;
					int hours = leftTime / 3600;
					int minutes = (leftTime % 3600) / 60;
					int seconds = leftTime % 60;

					cout << "Current time : " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds." << endl;

					int remainingHours = leftTime / 3600;
					int remainingMinutes = (leftTime % 3600) / 60;
					int remainingSeconds = leftTime % 60;

					cout << "Time remaining until midnight: " << remainingHours << " hours, " << remainingMinutes << " minutes, " << remainingSeconds << " seconds." << endl; */

					//Task5

	int workDayHours = 8;
	int totalSecondsInDay = 86400;
	int secondsPassed;

	cout << "Enter the time passed since the beginning of the work day : ";
	cin >> secondsPassed;

	int remainingSeconds = totalSecondsInDay - secondsPassed;
	int remainingHours = remainingSeconds / 3600;

	cout << "Remaining hours at work: " << remainingHours << " hours." << endl;







}