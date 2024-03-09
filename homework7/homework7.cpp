#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{

    //Task 1

/*  cout << "Menu:" << endl;
    cout << "1. Print horizontal line" << endl;
    cout << "2. Print vertical line" << endl;

    char choice;
    cout << "Choose an option (1 or 2): ";
    cin >> choice;

    char symbol;
    cout << "Enter symbol: ";
    cin >> symbol;

    string speed;
    int delay;
    while (true)
    {
        cout << "Enter speed (fast, normal, slow): ";
        cin >> speed;

        if (speed == "fast")
        {
            delay = 1000;
            break;
        }
        else if (speed == "normal")
        {
            delay = 2000;
            break;
        }
        else if (speed == "slow")
        {
            delay = 3000;
            break;
        }
        else
        {
            cout << "Unknown speed. Please enter 'fast', 'normal' or 'slow'." << endl;
        }
    }
    if (choice == '1')
    {
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                cout << symbol;
                cout.flush();
                Sleep(delay);
            }
            cout << endl;
        }
    } 
    else if (choice == '2')
    {
        for (int i = 0; i < 5; ++i)
        {
            cout << symbol << endl;
            Sleep(delay);
        }
    }
    else
    {
        cout << "Invalid choice" << endl;
    }*/





    //Task 2





/*  srand(time(0));

    int userScore = 0;
    int computerScore = 0;

    cout << "Welcome to the Dice Game!" << endl;

    char startGame;
    cout << "Enter '1' to start the game: ";
    cin >> startGame;

    switch (startGame)
    {
    case '1':
    {
        for (int i = 0; i < 3; ++i)
        {

            int userRoll1 = (rand() % 6) + 1;
            int userRoll2 = (rand() % 6) + 1;
            int userTotal = userRoll1 + userRoll2;
            cout << "You rolled: " << userRoll1 << " and " << userRoll2 << " (Total: " << userTotal << ")" << endl;
            userScore += userTotal;

            int computerRoll1 = (rand() % 6) + 1;
            int computerRoll2 = (rand() % 6) + 1;
            int computerTotal = computerRoll1 + computerRoll2;
            cout << "Computer rolled: " << computerRoll1 << " and " << computerRoll2 << " (Total: " << computerTotal << ")" << endl;
            computerScore += computerTotal;

            cout << "Your current score: " << userScore << endl;
            cout << "Computer's current score: " << computerScore << endl;
            cout << endl;
        }
        switch (userScore > computerScore ? 1 : (userScore < computerScore ? 2 : 0)) {
        case 1:
            cout << "Congratulations! You win!" << endl;
            break;
        case 2:
            cout << "Computer wins. Better luck next time!" << endl;
            break;
        default:
            cout << "It's a tie!" << endl;
        }
        break;
    }
    default:
            cout << "Exiting the game. Goodbye!" << endl;
            break;
    }*/





    //Task 3





/*  const int SIZE = 10;
    int numbers[SIZE];

    srand(time(0));
    for (int i = 0; i < SIZE; ++i)
    {
        numbers[i] = rand() % 100;
    }

    cout << "Array: ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    int min = numbers[0];
    int max = numbers[0];
    for (int i = 1; i < SIZE; ++i)
    {
        if (numbers[i] < min)
        {
            min = numbers[i];
        }
        if (numbers[i] > max)
        {
            max = numbers[i];
        }
    }
    cout << "Minimum element: " << min << endl;
    cout << "Maximum element: " << max << endl; */




  
    //Task4




    
/*  const int monthsInYear = 12;
    double profits[monthsInYear];

    cout << "Enter profits for each month:" << endl;
    for (int i = 0; i < monthsInYear; ++i)
    {
        cout << "Month " << i + 1 << ": ";
        cin >> profits[i];
    }

    int startMonth, endMonth;
    cout << "Enter the range (start month and end month): ";
    cin >> startMonth >> endMonth;

    double maxProfit = profits[startMonth - 1];
    double minProfit = profits[startMonth - 1];
    int maxMonth = startMonth;
    int minMonth = startMonth;
    for (int i = startMonth; i <= endMonth; ++i)
    {
        if (profits[i - 1] > maxProfit || i == startMonth)
        {
            maxProfit = profits[i - 1];
            maxMonth = i;
        }
        if (profits[i - 1] < minProfit || i == startMonth)
        {
            minProfit = profits[i - 1];
            minMonth = i;
        }
    }
    cout << "Maximum profit in the range: Month " << maxMonth << " ($" << maxProfit << ")" << endl;
    cout << "Minimum profit in the range: Month " << minMonth << " ($" << minProfit << ")" << endl;*/





    
    //Task5





    float arr[10]{ 2.5, -4.3, 6.7, -8.9, 10.1, -12.3, 14.5, -16.7, 18.9, -20.0 };
    float sumNegatives = 0;
    float productMinMax = 1;
    float productEvenIndices = 1;
    float sumBetweenNegatives = 0;
    int firstNegativeIndex = -1;
    int lastNegativeIndex = -1;

    
    for (size_t i = 0; i < 10; i++) 
    {
        if (arr[i] < 0)
            sumNegatives += arr[i];
    }
    for (int i = 0; i < 10; ++i) 
    {
        if (arr[i] < 0) 
        {
            if (firstNegativeIndex == -1) firstNegativeIndex = i;
            lastNegativeIndex = i;
        }
    }
    int startIndex = min(firstNegativeIndex, lastNegativeIndex) + 1;
    int endIndex = max(firstNegativeIndex, lastNegativeIndex) - 1;
    for (int i = startIndex; i <= endIndex; ++i) 
    {
        productMinMax *= arr[i];
    }
    for (size_t i = 0; i < 10; i++) 
    {
        if (i % 2 == 0) 
        {
            productEvenIndices *= arr[i];
        }
    }
    for (int i = firstNegativeIndex + 1; i < lastNegativeIndex; ++i) 
    {
        sumBetweenNegatives += arr[i];
    }
    cout << "Sum of negative: " << sumNegatives << endl;
    cout << "Product of min to max: " << productMinMax << endl;
    cout << "Product of even indices: " << productEvenIndices << endl;
    cout << "Sum of between first and last negative elements: " << sumBetweenNegatives << endl;









}