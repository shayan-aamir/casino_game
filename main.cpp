#include <iostream>
#include <ctime>
#include <string>
using namespace std;
struct Num
{
    int num1, num2, sum, extracard;
};
void PrintCard1(int n1, int n2, int n3, int sum)
{
    cout << "===========" << endl;
    cout << sum << endl;
    cout << "===========" << endl;
    cout << "First Card:\t" << n1 << endl;
    cout << "Second Card:\t" << n2 << endl;
    cout << "Extra Card:\t" << n3 << endl;
}
void PrintCard2(int n1, int n2, int sum)
{
    cout << "===========" << endl;
    cout << sum << endl;
    cout << "===========" << endl;
    cout << "This is a natural win 8/9" << endl;
    cout << "First Card:\t" << n1 << endl;
    cout << "Second Card:\t" << n2 << endl;
}
bool playAgain(char x, int money)
{
    if (money > 0)
    {
        if (x == 'y' || x == 'Y')
        {
            return true;
        }
        else if (x == 'n' || x == 'N')
        {
            cout << "Thanks for playing." << endl;
            return false;
        }
    }
    else
    {
        cout << "Insufficient balance" << endl;
        return false;
    }
}
int winnerfunc(int bankerCard, int playerCard)
{
    if (bankerCard > playerCard)
    {
        cout << "===========" << endl;
        cout << "Banker wins" << endl;
        return 1;
    }
    else if (bankerCard < playerCard)
    {
        cout << "===========" << endl;
        cout << "Player wins" << endl;
        return 2;
    }
    else
    {
        cout << "===========" << endl;
        cout << "Draw" << endl;
        return 3;
    }
}
int declareWinner(int winner, int dec, int bet)
{
    if (winner == dec)
    {
        cout << "You win" << endl;
        return bet;
    }
    if (winner == 3)
    {
        cout << "Tie Game" << endl;
        return 0;
    }
    else
    {
        cout << "You loose" << endl;
        bet *= -1;
        return bet;
    }
}
int main()
{
    system("Color 8F");
    srand(time(NULL));
    string name;
    int bet, dec, winner, prize;
    char play;
    bool logic = true;
    int money = 10000;
    cout << "==============================" << endl;
    cout << "To Start, please enter your card" << endl;
    cout << "Enter your name:  ";
    getline(cin, name);
    cout << "\nGood evening, " << name << endl;
    cout << "==============================" << endl;
    cout << "WELCOME TO VIRTUAL BACCARAT TABLE" << endl;
    cout << "=================================" << endl;
    do
    {
        cout << "Current Balance:  " << money << endl;
        cout << "1-BANKER " << endl
             << "2- PLAYER" << endl;
        cout << "Choose your bet " << endl;
        while (!(cin >> dec) || (dec < 1 || dec > 2))
        {
            cin.clear();
            cout << "Choose your bet " << endl;
            cout << "1-BANKER " << endl
                 << "2- PLAYER" << endl;
        }
        do
        {
            cout << "Place your bet, PHP: ";
            cin >> bet;
        } while (bet > money);
        cout << "\n==============================\n";
        cout << "      =" << " BANKER'S CARD  " << "=\n";
        cout << "==============================\n";
        struct Num banker;
        banker.num1 = rand() % 10 + 1;
        banker.num2 = rand() % 10 + 1;
        banker.sum = banker.num1 + banker.num2;
        banker.sum = banker.sum % 10;
        if (banker.sum != 9 && banker.sum != 8)
        {
            banker.extracard = rand() % 10 + 1;
            banker.sum += banker.extracard;
            banker.sum = banker.sum % 10;
            PrintCard1(banker.num1, banker.num2, banker.extracard, banker.sum);
        }
        else
        {
            PrintCard2(banker.num1, banker.num2, banker.sum);
        }
        cout << "\n==============================\n";
        cout << "      =" << " PLAYER'S CARD  " << "=\n";
        cout << "==============================\n";
        struct Num player;
        player.num1 = rand() % 10 + 1;
        player.num2 = rand() % 10 + 1;
        player.sum = player.num1 + player.num2;
        player.sum = player.sum % 10;
        if (player.sum != 9 && player.sum != 8)
        {
            player.extracard = rand() % 10 + 1;
            player.sum += player.extracard;
            player.sum = player.sum % 10;
            PrintCard1(player.num1, player.num2, player.extracard, player.sum);
        }
        else
        {
            PrintCard2(player.num1, player.num2, player.sum);
        }
        winner = winnerfunc(banker.sum, player.sum);
        prize = declareWinner(winner, dec, bet);
        cout << "PHP " << prize << endl;
        money += prize;
        cout << "Current Money, PHP " << money << "\n\n";
        cout << "PLAY AGAIN? Y/N ";
        cin >> play;
        logic = playAgain(play, money);
    } while (logic != false);
}