#include <bits/stdc++.h>
using namespace std;

// data rs
class Rs {
public:
	string namaRumahSakit;
	string lokasi;
	int ketersediaanRuang;
	float rating;
	string kontak;
	string namaDokter;
	int harga;
};

// data pasien
class Pasien : public Rs {
public:
	string namaPasien;
	int idPasien;
};

// data rs
void PrintRsData(
	vector<Rs>& rs)
{
	cout << " Data Rumah sakit :"
		<< endl;

	cout << "Nama_RS	 "
		<< "Lokasi	 "
		<< "Ketersediaan_Ruang	 "
		<< "Rating	 "
		<< "Kontak	 "
		<< "Nama_Dokter	 "
		<< "Harga	 \n";

	for (int i = 0; i < 4; i++) {
		cout << rs[i].namaRumahSakit
			<< "				 "
			<< "	 "
			<< rs[i].lokasi
			<< "		 "
			<< rs[i].ketersediaanRuang
			<< "				 "
			<< rs[i].rating
			<< "		 "
			<< rs[i].kontak
			<< "			 "
			<< rs[i].namaDokter
			<< "				 "
			<< "	 "
			<< rs[i].harga
			<< "		 "
			<< endl;
	}

	cout << endl
		<< endl;
}

// Fungsi print pada pasien
// data in rs
void PrintPasienData(
	vector<Pasien>& pasiens,
	vector<Rs>& rs)
{
	cout << "PRINT pasien DATA:"
		<< endl;
	cout << "Nama_Pasien	 "
		<< "Id_Pasien	 "
		<< "Kontak	 "
		<< "Lokasi_Rs	 "
		<< "Pengeluaran	 \n";

	for (int i = 0; i < 4; i++) {
		cout << pasiens[i].namaPasien
			<< "			 "
			<< "		 "
			<< pasiens[i].idPasien
			<< "			 "
			<< "		 "
			<< pasiens[i].kontak
			<< "				 "
			<< pasiens[i].namaRumahSakit
			<< "				 "
			<< pasiens[i].harga
			<< "		 "
			<< endl;
	}

	cout << endl
		<< endl;
}

// Fungsi pembanding untuk mengurutkan
// data rumah sakit berdasarkan nama
bool compareName(Rs& A, Rs& B)
{
	return A.namaRumahSakit > B.namaRumahSakit;
}

// Berfungsi untuk mengurutkan rumah sakit
// data dengan nama
void SortRsByNama(
	vector<Rs> rs)
{
	// Sort the data
	sort(rs.begin(),
		rs.end(),
		compareName);

	cout << "SORT BY NAME:"
		<< endl
		<< endl;
	PrintRsData(rs);
}

// Fungsi pembanding untuk mengurutkan
// data rumah sakit menurut peringkat
bool compareRating(Rs& A, Rs& B)
{
	return A.rating > B.rating;
}

// Berfungsi untuk mengurutkan rumah sakit
// data dengan pemberian nama
void SortRsByRating(vector<Rs> rs)
{
	sort(rs.begin(),
		rs.end(),
		compareRating);

	cout << "SORT BY Rating:"
		<< endl
		<< endl;

	PrintRsData(rs);
}

// Fungsi pembanding untuk mengurutkan
// data rumah sakit menurut ketersediaan ruang
bool compareRuang(Rs& A, Rs& B)
{
	return A.ketersediaanRuang > B.ketersediaanRuang;
}

// Berfungsi untuk mengurutkan rumah sakit
// data menurut ruang Tersedia
void SortByKetersediaanRuang(
	vector<Rs> rs)
{
	sort(rs.begin(),
		rs.end(),
		compareRuang);

	cout << "SORT BY Available Beds:"
		<< endl
		<< endl;

	PrintRsData(rs);
}

// Fungsi pembanding untuk mengurutkan
// data rumah sakit menurut Harga Tempat Tidur
bool compareHarga(Rs& A, Rs& B)
{
	return A.harga < B.harga;
}

// Berfungsi untuk mengurutkan rumah sakit
// data menurut Harga Tempat Tidur
void SortByHargaTempatTidur(
	vector<Rs> rs)
{
	sort(rs.begin(),
		rs.end(),
		compareHarga);

	cout << "SORT BY Available Beds Price:"
		<< endl
		<< endl;

	PrintRsData(rs);
}

// Fungsi pembanding untuk mengurutkan
// data rumah sakit menurut Kota
void PrintRsByCity(
	string city, vector<Rs> rs)
{
	cout << "PRINT rs by Name :"
		<< city << endl;

	cout << "RSnama	 "
		<< "Lokasi	 "
		<< "Ketersediaan_Ruang	 "
		<< "Rating	 "
		<< "Kontak	 "
		<< "Nama_Dokter	 "
		<< "Harga\n";

	for (int i = 0; i < 4; i++) {

		if (rs[i].lokasi != city)
			continue;
		cout << rs[i].namaRumahSakit
			<< "				 "
			<< "	 "
			<< rs[i].lokasi
			<< "		 "
			<< rs[i].ketersediaanRuang
			<< "				 "
			<< rs[i].rating
			<< "		 "
			<< rs[i].kontak
			<< "			 "
			<< rs[i].namaDokter
			<< "			 "
			<< "		 "
			<< rs[i].harga
			<< "		 "
			<< endl;
	}
	cout << endl
		<< endl;
}

// Fungsi untuk mengimplementasikan Rumah Sakit
// Sistem manajemen
void RsManagement(
	string pasienNama[], int pasienId[],
	string pasienKontak[], int bookingCost[],
	string rsNama[], string lokasi[], int ruang[],
	float ratings[], string kontak[],
	string namaDokter[], int harga[])
{
	// Menyimpan data Rumah Sakit
// dan data pengguna
	vector<Rs> rs;

	// Create Objects for hospital
	// and the users
	Rs h;

	// Inisialisasi data
	for (int i = 0; i < 4; i++) {
		h.namaRumahSakit = rsNama[i];
		h.lokasi = lokasi[i];
		h.ketersediaanRuang = ruang[i];
		h.rating = ratings[i];
		h.kontak = kontak[i];
		h.namaDokter = namaDokter[i];
		h.harga = harga[i];
		rs.push_back(h);
	}

	// menyimpan data pasien
	vector<Pasien> pasiens;
	Pasien p;

	// Inisialisasi data
	for (int i = 0; i < 4; i++) {
		p.namaPasien = pasienNama[i];
		p.idPasien = pasienId[i];
		p.kontak = pasienKontak[i];
		p.harga = bookingCost[i];
		pasiens.push_back(p);
	}

	cout << endl;

	// Call the various operations
	PrintRsData(rs);
	PrintPasienData(pasiens, rs);

	SortRsByNama(rs);
	SortRsByRating(rs);
	PrintRsByCity("Bangalore", rs);
	SortByKetersediaanRuang(rs);
	SortByHargaTempatTidur(rs);
}

// Driver Code
int main()
{
	// Stores hospital data and
	// the user data
	string pasienNama[] = { "P1", "P2", "P3", "P4" };
	int pasienId[] = { 2, 3, 4, 1 };
	string pasienKontak[]
		= { "234534XXX7", "234576XXX2", "857465XXX9",
			"567657XXX0" };
	int bookingCost[] = { 1000, 1200, 1100, 600 };

	string rsNama[] = { "H1", "H2", "H4", "H3" };
	string lokasi[] = { "sleman", "diy",
						"turi ", "bantul" };
	int ruang[] = { 4, 5, 6, 9 };
	float ratings[] = { 5.2, 4.1, 3.4, 5.9 };
	string kontak[]
		= { "657534XXX7", "298766XXX2", "324565XXX9",
			"343456XXX4" };
	string namaDokter[] = { "D1", "D4", "D3", "D2" };
	int harga[] = { 100, 200, 100, 290 };

	// Function Call
	RsManagement(
		pasienNama, pasienId, pasienKontak,
		bookingCost, rsNama, lokasi, ruang,
		ratings, kontak, namaDokter, harga);

	return 0;
}

