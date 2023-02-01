#include <iostream>
#include "string.h"
#include <fstream>
using namespace std;
//sozlukteki ingilizce kelimeleri ayirma
string englishSozcuk(string a)
{
  string engS;
  int i = 0;
  for (; i < a.length(); i++)
  {
    if ((a.at(i) == ' ') && (a.at((i + 1)) == ' '))
    {
      break;
    }
  }

  engS = a.substr(0, i);
  return engS;
}
//sozlukteki turkce kelimeleri ayirma
string turkishSocuk(string a, string eng)
{

  string trS;
  int i = eng.length();
  for (; i < a.length(); i++)
  {
    if ((a.at(i) != ' ') && (a.at(i + 1) != ' '))
    {
      break;
    }
  }

  trS = a.substr(i, a.length());
  return trS;
}
//sozlugu sifreleme
int hashFunc(string a, int tablesize)
{
  int hashCode = 0;
  for (int i = 0; i < a.length(); i++)
  {
    hashCode += a[i];
  }
  return hashCode % tablesize;
}
//sozluk icerisinde arama yapma
string hashSearch(string aranacakS, string table[][2])
{
  int location = hashFunc(aranacakS, 5999);

  if (table[location][0] == aranacakS)
  {
    return table[location][1];
  }
  else
  {
    int a = 1;
    while (table[location][0] != aranacakS)
    {
      location = (location + (a * a)) % 5999;
      a++;
    }
    return table[location][1];
  }
}
int main(int argc, char const *argv[])
{
  string satir[6000];
  string sozluk[5721][2];
  string sifrelenmisSozluk[6000][2];
  string sifrelenmisSozlukImport[6000][2];
  int location;
  //sozluk.txt nin cekilmesi turkce ingilizce ayrilmasi ve sifrelenmesi
  ifstream dosyaOku("C:/Users/Celal/Documents/AdvencedCppApp/src/sozluk.txt");
  if (dosyaOku.is_open())
  {
    for (int i = 0; i < 6000 && getline(dosyaOku, satir[i]); i++)
      ;
    dosyaOku.close();
  }
  for (int i = 0; i < 5721; i++)
  {
    sozluk[i][0] = englishSozcuk(satir[i]);
    sozluk[i][1] = turkishSocuk(satir[i],sozluk[i][0]);
  }

  for (int i = 0; i < 5721; i++)
  {
    location=hashFunc(sozluk[i][0],6000);
    if (sifrelenmisSozluk[location][0] == "")
    {
      sifrelenmisSozluk[location][0] = sozluk[i][0];
      sifrelenmisSozluk[location][1] = sozluk[i][1];
    }else{
      int a = 1;
      location=(hashFunc(sozluk[i][0],6000) + (a * a))%6000;
      while(sifrelenmisSozluk[location][0] != "")
      {
        a++;
        location=(hashFunc(sozluk[i][0],6000) + (a * a))%6000;
      }
      sifrelenmisSozluk[location][0] = sozluk[i][0];
      sifrelenmisSozluk[location][1] = sozluk[i][1];
    }
  }
  ofstream dosyaYaz("sozluk1.txt");
  for (int i = 0; i < 6000; i++)
  {
    dosyaYaz<<sifrelenmisSozluk[i][0]<<"                    "<<sifrelenmisSozluk[i][1]<<endl;
  }
  dosyaYaz.close();
  //ust kısımda sifrelenen sozlugun cekilmesi ve arama yapilmasi
  ifstream dosyaOku2("C:/Users/Celal/Documents/AdvencedCppApp/src/sozluk1.txt");
  if (dosyaOku2.is_open())
  {
    for (int i = 0; i < 6000 && getline(dosyaOku2, satir[i]); i++)
      ;
    dosyaOku2.close();
  }
  for (int i = 0; i < 6000; i++)
  {
    sifrelenmisSozlukImport[i][0] = englishSozcuk(satir[i]);
    sifrelenmisSozlukImport[i][1] = turkishSocuk(satir[i], sifrelenmisSozlukImport[i][0]);
  }
  string aranacakSozcuk;

  while (true)
  {
    cout << "Aramak istediginiz kelimeyi yaziniz(cikis icin q)" << endl;
    getline(cin, aranacakSozcuk);
    //cout << hashSearch(aranacakSozcuk, sifrelenmisSozlukImport) << endl;
    if (aranacakSozcuk == "q")
    {
      cout << "Kullandiginiz icin tesekkurler" << endl;
      break;
    }
    else
    {
      if (hashSearch(aranacakSozcuk, sifrelenmisSozlukImport) != "Aranan deger bulunamadi")
      {
        cout << hashSearch(aranacakSozcuk, sifrelenmisSozlukImport) << endl;
      }else{
        cout<<"bulunamadi"<<endl;
      }
    }
  }
  system("pause");
  return 0;
}
