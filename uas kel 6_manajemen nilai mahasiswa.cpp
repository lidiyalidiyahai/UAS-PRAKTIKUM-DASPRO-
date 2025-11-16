#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// fungsi ubah string ke lowercase
string lowerStr(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

// Fungsi untuk menghitung rata-rata
float hitungRata(float tugas, float uts, float uas) {
    return (tugas + uts + uas) / 3;
}

// Fungsi untuk menentukan grade
char tentukanGrade(float rata) {
    if (rata >= 85) return 'A';
    else if (rata >= 70) return 'B';
    else if (rata >= 55) return 'C';
    else if (rata >= 40) return 'D';
    else return 'E';
}

// Fungsi untuk menampilkan data
void tampilData(int jumlah, string nama[], string nim[], float tugas[], float uts[], float uas[], float rata[], char grade[]) {
    cout << "\n===== DAFTAR NILAI MAHASISWA =====\n";
    int i = 0;

    while (i < jumlah) {
        cout << "\nData ke-" << i + 1;
        cout << "\nNama      : " << nama[i];
        cout << "\nNIM       : " << nim[i];
        cout << "\nTugas     : " << tugas[i];
        cout << "\nUTS       : " << uts[i];
        cout << "\nUAS       : " << uas[i];
        cout << "\nRata-rata : " << rata[i];
        cout << "\nGrade     : " << grade[i] << endl;
        i++;
    }
}

int main() {
    const int MAX = 100;
    string nama[MAX], nim[MAX];
    float tugas[MAX], uts[MAX], uas[MAX], rata[MAX];
    char grade[MAX];
    int jumlah = 0, pilih;
    char ulang;

    do {
        system("cls"); // bersihkan layar menu

        cout << "\n===== SISTEM MANAJEMEN NILAI MAHASISWA =====";
        cout << "\n1. Input Data Mahasiswa";
        cout << "\n2. Tampilkan Semua Data";
        cout << "\n3. Cari Mahasiswa Berdasarkan NIM";
        cout << "\n4. Update Data";
        cout << "\n5. Hapus Data";
        cout << "\n6. Keluar";
        cout << "\n============================================";
        cout << "\nPilih menu: ";
        cin >> pilih;

        switch (pilih) {

        // INPUT DATA
        case 1: {
            system("cls");

            cout << "\nMasukkan jumlah mahasiswa: ";
            cin >> jumlah;

            for (int i = 0; i < jumlah; i++) {
                cout << "\nData ke-" << i + 1 << endl;

                cout << "Nama  : ";
                cin.ignore();
                getline(cin, nama[i]);

                cout << "NIM   : ";
                getline(cin, nim[i]);

                cout << "Nilai Tugas : ";
                cin >> tugas[i];

                cout << "Nilai UTS   : ";
                cin >> uts[i];

                cout << "Nilai UAS   : ";
                cin >> uas[i];

                rata[i] = hitungRata(tugas[i], uts[i], uas[i]);
                grade[i] = tentukanGrade(rata[i]);
            }
            break;
        }

        // TAMPILKAN SEMUA
        case 2:
            system("cls");
            tampilData(jumlah, nama, nim, tugas, uts, uas, rata, grade);
            break;

        // CARI DATA
        case 3: {
            system("cls");

            string cariNIM;
            bool ditemukan = false;

            cout << "\nMasukkan NIM yang dicari: ";
            cin.ignore();
            getline(cin, cariNIM);

            string lowerCari = lowerStr(cariNIM);

            for (int i = 0; i < jumlah; i++) {
                if (lowerStr(nim[i]) == lowerCari) {
                    cout << "\nData ditemukan!";
                    cout << "\nNama      : " << nama[i];
                    cout << "\nNIM       : " << nim[i];
                    cout << "\nRata-rata : " << rata[i];
                    cout << "\nGrade     : " << grade[i] << endl;
                    ditemukan = true;
                    break;
                }
            }

            if (!ditemukan)
                cout << "\nData tidak ditemukan!\n";

            break;
        }

        // UPDATE DATA
        case 4: {
            system("cls");

            string cariNIM;
            bool ditemukan = false;

            cout << "\nMasukkan NIM data yang mau diupdate: ";
            cin.ignore();
            getline(cin, cariNIM);

            for (int i = 0; i < jumlah; i++) {
                if (lowerStr(nim[i]) == lowerStr(cariNIM)) {
                    cout << "\n=== UPDATE DATA ===\n";

                    cout << "Nama baru  : ";
                    getline(cin, nama[i]);

                    cout << "NIM baru   : ";
                    getline(cin, nim[i]);

                    cout << "Nilai Tugas : ";
                    cin >> tugas[i];
                    cout << "Nilai UTS   : ";
                    cin >> uts[i];
                    cout << "Nilai UAS   : ";
                    cin >> uas[i];

                    rata[i] = hitungRata(tugas[i], uts[i], uas[i]);
                    grade[i] = tentukanGrade(rata[i]);

                    cout << "\nData berhasil diupdate!\n";
                    ditemukan = true;
                    break;
                }
            }

            if (!ditemukan)
                cout << "\nData tidak ditemukan!\n";

            break;
        }

        // DELETE DATA
        case 5: {
            system("cls");

            string hapusNIM;
            bool ditemukan = false;

            cout << "\nMasukkan NIM yang akan dihapus: ";
            cin.ignore();
            getline(cin, hapusNIM);

            for (int i = 0; i < jumlah; i++) {
                if (lowerStr(nim[i]) == lowerStr(hapusNIM)) {

                    for (int j = i; j < jumlah - 1; j++) {
                        nama[j] = nama[j + 1];
                        nim[j] = nim[j + 1];
                        tugas[j] = tugas[j + 1];
                        uts[j] = uts[j + 1];
                        uas[j] = uas[j + 1];
                        rata[j] = rata[j + 1];
                        grade[j] = grade[j + 1];
                    }

                    jumlah--;
                    cout << "\nData berhasil dihapus!\n";
                    ditemukan = true;
                    break;
                }
            }

            if (!ditemukan)
                cout << "\nData tidak ditemukan!\n";

            break;
        }

        case 6:
            cout << "\nTerima kasih!\n";
            return 0;

        default:
            cout << "\nPilihan tidak valid!\n";
        }

        cout << "\nKembali ke menu? (y/n): ";
        cin >> ulang;
        ulang = tolower(ulang);

    } while (ulang == 'y');

    return 0;
}