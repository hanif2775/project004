#include <iostream>
#include <string>

using namespace std;

struct Pelanggan {
  string nama;
  int umur;
  string alamat;
  string nomor_telepon;
  Pelanggan* next;
};

// Fungsi untuk menambahkan data pelanggan
Pelanggan* tambahPelanggan(Pelanggan* head) {
  Pelanggan* pelangganBaru = new Pelanggan;
  cout << "Masukkan nama pelanggan: ";
  getline(cin, pelangganBaru->nama);
  cout << "Masukkan umur pelanggan: ";
  cin >> pelangganBaru->umur;
  cin.ignore();
  cout << "Masukkan alamat pelanggan: ";
  getline(cin, pelangganBaru->alamat);
  cout << "Masukkan nomor telepon pelanggan: ";
  getline(cin, pelangganBaru->nomor_telepon);

  pelangganBaru->next = NULL;

  if (head == NULL) {
    head = pelangganBaru;
    cout << "Data pelanggan berhasil ditambahkan." << endl;
    return head;
  }

  Pelanggan* current = head;
  while (current->next != NULL) {
    current = current->next;
  }

  current->next = pelangganBaru;
  cout << "Data pelanggan berhasil ditambahkan." << endl;

  return head;
}

// Fungsi untuk menghapus data pelanggan
Pelanggan* hapusPelanggan(Pelanggan* head) {
  string namaPelanggan;
  cout << "Masukkan nama pelanggan yang ingin dihapus: ";
  getline(cin, namaPelanggan);

  Pelanggan* current = head;
  Pelanggan* prev = NULL;

  while (current != NULL) {
    if (current->nama == namaPelanggan) {
      if (prev == NULL) {
        head = current->next;
      } else {
        prev->next = current->next;
      }
      delete current;
      cout << "Data pelanggan berhasil dihapus." << endl;
      return head;
    }
    prev = current;
    current = current->next;
  }

  cout << "Pelanggan tidak ditemukan." << endl;
  return head;
}

// Fungsi untuk menampilkan semua data pelanggan
void tampilkanDataPelanggan(Pelanggan* head) {
  cout << "Data Pelanggan:" << endl;
  Pelanggan* current = head;
  while (current != NULL) {
    cout << "Nama: " << current->nama << endl;
    cout << "Umur: " << current->umur << endl;
    cout << "Alamat: " << current->alamat << endl;
    cout << "Nomor Telepon: " << current->nomor_telepon << endl;
    cout << endl;
    current = current->next;
  }
}

// Fungsi utama
int main() {
  Pelanggan* head = NULL;

  while (true) {
    int pilihan;
    cout << "Menu:" << endl;
    cout << "1. Tambah Pelanggan" << endl;
    cout << "2. Hapus Pelanggan" << endl;
    cout << "3. Tampilkan Data Pelanggan" << endl;
    cout << "4. Keluar" << endl;
    cout << "Pilihan Anda: ";
    cin >> pilihan;
    cin.ignore();

    switch (pilihan) {
      case 1:
        head = tambahPelanggan(head);
break;
case 2:
head = hapusPelanggan(head);
break;
case 3:
tampilkanDataPelanggan(head);
break;
case 4:
cout << "Terima kasih." << endl;
return 0;
default:
cout << "Pilihan tidak valid." << endl;
}
}
}
