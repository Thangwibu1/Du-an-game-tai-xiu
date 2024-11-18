#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Player
{
    string name;
    int coin;

    friend istream& operator>>(istream &is, Player &player) {
        cout << "Nhap ten nguoi choi: ";
        is.ignore();
        getline(cin, player.name);
        cout << "Nhap so tien ban muon nap vao game: ";
        is.ignore();
        cin >> player.coin;

        return is;
    }
    friend ostream& operator<<(ostream &os, Player &player) {
        os << "Dan choi: "<< player.name << "\n" ;
        os << "Coin: " << player.coin << "\n";

        return os;
    }
};

int show_menu();
int random();
void choi_tro_choi(Player *player);
void tao_tai_khoan(Player *&player, int &size);

int main() {
    int size = 0;
    Player *players = new Player[size];
    while (true)
    {
        int choose = show_menu();
        system("cls");
        switch (choose)
        {
        case 1:
            choi_tro_choi(players);
            break;
        case 2:
            tao_tai_khoan(players, size);
            break;
        case 0:
            cout << "Bye Bye!\n";
            return 0;
        default:
            cout << "eror!\n";
            break;
        }
        bool is_continue;
        cout << "Ban co muon tiep tuc!(1/0)?";
        cin >> is_continue;
        if (!is_continue)
        {
            cout << "Bye bye!";
            return 0;
        }
        
    }
    
    return  0;
}

void tao_tai_khoan(Player *&player, int &size) {
    Player new_player;
    int new_size = size + 1;
    cout << "Moi dan choi tao tai khoan.\n ";
    cin >> new_player;
    Player *tmp = new Player;
    for (int i = 0; i < size; i++)
    {
        tmp[i] = player[i];
    }
    tmp[size] = new_player;
    delete[] player;
    player = tmp;
    size = new_size;
    cout << "Tao tai khoan thanh cong!\n";
}

int show_menu() {
    system("cls");
    int choose;
    cout << "======MENU======\n";
    cout << "1. Choi tro choi.\n";
    cout << "2. Tao tai khoan.\n";
    cout << "0. Thoat tro choi.\n";

    cout << "Lua chon cua ban la: ";
    cin >> choose;

    return choose;
}
int random() {
    srand(time(NULL));
    int random_value[2];
    int sum_value = 0;
    for (int i = 0; i < 2; i++)
    {
        sum_value += random_value[i] = rand() % 10 + 1;
    }
    while (sum_value > 12)
    {
        sum_value--;
    }
    
    return sum_value;
}

void choi_tro_choi(Player *player) {
    int sum = random();
    bool value;
    cout << "Dan choi chon chan hay le(1. chan/ 0. le)?";
    cin >> value;
    if (!value)
    {
        if (sum % 2 == 1)
        {
            cout << "Dan choi " << player[0].name << " da chien thang!\n";
        }
        else
        {
            cout << "Dan choi " << player[0].name << " di ve! Phong Cach, Phong Cach\n";
        }
    }
    else
    {
        if (sum % 2 == 0)
        {
            cout << "Dan choi " << player[0].name << " da chien thang!\n";
        }
        else
        {
            cout << "Dan choi " << player[0].name << " di ve! Phong Cach, Phong Cach\n";
        }
    }
    cout << random() << endl;
}
