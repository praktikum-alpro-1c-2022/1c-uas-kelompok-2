#include <iostream>
#include <string>

using namespace std;

// Struktur data untuk menyimpan informasi mengenai user
struct daftar{
    string namaUser;
    int uang;
};

// Panggil data dari struktur daftar
daftar userBaru;

// Struktur data untuk menyimpan informasi mengenai makanan atau minuman
struct MenuItem {
    string nama;
    int harga;
    int persediaan;
    int diskon;
};

// Array dari struktur data MenuItem
MenuItem menu[] = {
    {"Nasi Goreng",15000, 20, 10},
    {"Mie Goreng",12000, 30, 5},
    {"Sate Ayam",20000, 100, 5},
    {"Sate Kambing",30000, 100, 15},
    {"Ayam Geprek",11000, 50, 5},
    {"Es Teh",5000, 50, 1},
    {"Es Jeruk",7000, 35, 1},
    {"Kopi",5000, 15, 1},
};

// Ukuran array menu
const int menuSize = 8;

// Function untuk menampilkan daftar user pertama kali
void daftarUser(){
    cout << "Masukkan nama: ";
    cin >> userBaru.namaUser;
    cout << "Masukkan jumlah uang: ";
    cin >> userBaru.uang;
    system("cls");
    cout << "Terima kasih telah mendaftar, " << userBaru.namaUser << "." << endl;
    cout << "Anda mempunyai uang sebesar: Rp " << userBaru.uang << endl;
}

// Function untuk menampilkan daftar makanan dan minuman yang tersedia
void daftarMenu() {
    cout << "Daftar Makanan dan Minuman:" << endl;
     cout << "====================================================== " <<endl;
    for (int i = 0; i < menuSize; i++) {
        cout << i + 1 << ". " << menu[i].nama << " - Rp " << menu[i].harga << " - Stok: " << menu[i].persediaan<< endl;
    }
    cout <<  "====================================================== " <<endl;
    cout << "Beli lebih dari 4 akan mendapatkan harga diskon!"<<endl;
}

// Function untuk memproses pemesanan makanan atau minuman
void tempatPesanan(MenuItem* item, int jumlah) {
    // Cek apakah stok item yang diminta cukup
    if ((*item).persediaan < jumlah) {
        cout << "Maaf, stok " << (*item).nama << " tidak mencukupi." << endl;
        return;
    }

    // Kurangi persediaan item yang diminta
    (*item).persediaan -= jumlah;

    // Hitung harga item yang diminta dengan diskon yang sesuai
    int totalHarga = (*item).harga * jumlah;
    int diskon = (*item).diskon;
    // totalharga * diskon / 100 - totalharga
    int totalDiskon = totalHarga - (totalHarga * diskon / 100);

    // Kurangi uang yang dimiliki user sesuai dengan harga pemesanan
    // uang user - harga pesanan
    int totaluangUser = userBaru.uang -= totalHarga;

    // Cek apakah user masih memiliki uang yang cukup
    if (userBaru.uang < 0) {
        cout << "Maaf, Anda tidak memiliki uang yang cukup untuk memesan." << endl;
        // jika uang user tidak mencukupi program akan berhenti
        exit(0);
    }

    // Jika user memesan lebih dari atau sama dengan 4 maka akan mendapatkan diskon sebesar 10%
    if (diskon && jumlah >= 4){
        cout << "Selamat anda telah mendaptkan diskon sebesar " << (*item).diskon << "%!" << endl;
        cout << "Total harga pemesanan: Rp " << totalHarga << endl;
        cout << "Diskon " << (*item).diskon << "%" << " menjadi: Rp " << totalDiskon << endl;
        cout << "Uang anda sekarang: Rp " << totaluangUser << endl;
    }else{
        cout << "Total harga pemesanan: Rp " << totalHarga << endl;
        cout << "Uang anda sekarang: Rp " << totaluangUser << endl;
    }

}

    int main() {
    // Membersihkan layar
    system("cls");
    // Tampilkan menu utama
    cout << "Selamat datang di Restoran Kami!" << endl;
    cout << "Silakan daftar terlebih dahulu sebelum memesan:" << endl;
    daftarUser();
    cout << "Silakan pilih menu yang Anda inginkan:" << endl;
    daftarMenu();

    // Loop sampai user memutuskan untuk mengakhiri pemesanan
    while (true) {
        cout << "Masukkan nomor item yang ingin Anda pesan (0 untuk mengakhiri pemesanan): ";
        int itemNumber;
        cin >> itemNumber;

        // jika user menginputkan 0 maka programnya akan berhenti
        if (itemNumber == 0) {
            break;
        // Cek apakah nomor item yang dipilih valid
        }else if(itemNumber < 1 || itemNumber > menuSize) {
            cout << "Maaf, nomor item yang Anda masukkan tidak valid." << endl;
            continue;
        }

        cout << "Masukkan jumlah yang ingin Anda pesan: ";
        int Jumlah;
        cin >> Jumlah;

        // Isi variabel pointer dengan alamat dari element array menu yang dipilih oleh user
        MenuItem* item = &menu[itemNumber - 1];

        tempatPesanan(item, Jumlah);
    }

    return 0;
}
