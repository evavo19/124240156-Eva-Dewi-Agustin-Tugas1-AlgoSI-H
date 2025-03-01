#include <iostream>
#include <iomanip>
using namespace std;

string pasukan[] = {"Infantry", "Kavaleri", "Archer"};
const int MAX_PASUKAN = 3;

struct data
{
    int ID;
    string general;
    string type;
    int jumlah;
};

const int MAX_BATALYON = 100;
data batalyons[MAX_BATALYON];
int total_batalyon = 0;

bool type_pasukan(string type)
{
    for (int i = 0; i < MAX_PASUKAN; i++)
    {
        if (pasukan[i] == type)
            return true;
    }
    return false;
}

bool nama_general(string nama)
{
    for (int i = 0; i < total_batalyon; i++)
    {
        if (batalyons[i].general == nama)
            return true;
    }
    return false;
}

void tambah_bataylon()
{
    char ulang = 'Y';

    if (total_batalyon >= MAX_BATALYON)
    {
        cout << "Batas maksimal batalyon telah tercapai.\n";
        return;
    }

    data batalyon;
    batalyon.ID = total_batalyon + 1;
    cout << "Input General Name: ";
    cin.ignore();
    getline(cin, batalyon.general);

    if (nama_general(batalyon.general))
    {
        cout << "Nama general sudah terdaftar.\n";
        return;
    }

    cout << "Input Soldier Type (Infantry/Kavaleri/Archer): ";
    getline(cin, batalyon.type);

    if (!type_pasukan(batalyon.type))
    {
        cout << "Error: Tipe pasukan tidak valid.\n";
        return;
    }

    cout << "Input Soldier Quantity: ";
    cin >> batalyon.jumlah;

    if (batalyon.jumlah < 1)
    {
        cout << "Jumlah pasukan harus lebih dari 0.\n";
        return;
    }

    batalyons[total_batalyon++] = batalyon;
    cout << "Batalyon berhasil ditambahkan!\n";
    cout << setfill('=') << setw(40) << "" << endl;

    cout << "Apakah Anda ingin kembali ke log out (Y/N)? ";
    cin >> ulang;

    if (ulang != 'Y')
        exit(0);

    system("cls");
}

int binary_search(string nama)
{
    int left = 0, right = total_batalyon - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (batalyons[mid].general == nama)
            return mid;
        else if (batalyons[mid].general < nama)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;

    system("cls");
}

void cari_bataylon()
{
    if (total_batalyon == 0)
    {
        cout << "Tidak ada batalyon yang terdaftar.\n";
        return;
    }
    string nama_general;
    cout << "Nama General yang ingin anda cari: ";
    cin.ignore();
    getline(cin, nama_general);

    int index = binary_search(nama_general);
    if (index != -1)
    {
        cout << "Batalyon ditemukan : " << endl;
        cout << "ID : " << batalyons[index].ID << "\n";
        cout << "Nama General : " << batalyons[index].general << endl;
        cout << "Tipe Pasukan : " << batalyons[index].type << endl;
        cout << "Jumlah Pasukan : " << batalyons[index].jumlah << endl;
        cout << setfill('=') << setw(40) << "" << endl;
    }

    else
    {
        cout << "Batalyon tidak ditemukan." << endl;
    }
}

int main()
{
    int pilih;

    do
    {
        cout << "Daftar Menu!!!" << endl;
        cout << "1. Tambah Bataylon" << endl;
        cout << "2. Cari Bataylon" << endl;
        cout << "Pilih Menu : ";
        cin >> pilih;

        system("cls");

        switch (pilih)
        {
        case 1:
            tambah_bataylon();
            break;
        case 2:
            cari_bataylon();
            break;

        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilih != 2);

    return 0;
}