
## Getting Started

Bu program asıl amacı hash algoritması ile sözlük.txt içindeki bilgilerin yeniden sözlük1.txt içinde
organize edilmesidir.Hash algoritması kişinin kendi algoritmasıdır. Bir çeşit adres bilgisi ile direk
kelimeye erişimdir.Program öncelikle sözlük.txt den verileri okuyarak yeniden organize ederek sözlük1.txt 
içine yerleştirir.Hash algoritmasında önemli olan iki kriter vardır. Birincisi dosya boyutunu azaltmak
ikincisi ise çakışma sayısının az olmasıdır.Ama ikisi birbirine karşıdır.Biraz daha açıklarsak çakışma
çok olursa daha sıkı yerleştirme yapacağından dosya boyutu küçülür ama oluşma zamanı (disket için) oldukça
uzar.Eğer çakışma sayısı az olursa bu durumda oluşan dosya boyutu çok büyür ama bu sefer oluşma zamanı
(disket için) oldukça azalır. Bu program disketlerde çalıştırılınca daha anlamlı olur. Olay şudurki en 
iyi hash algoritmasını bulup hem oluşma zamanını hemde dosya boyutunu ortalama seviyeye çekmek gerekir.

## Folder Structure

The workspace contains a folders by default, where:

- `src`: the folder to maintain sources

Meanwhile, the compiled output files will be generated in the `bin` folder by default.

> If you want to customize the folder structure, open `.vscode/settings.json` and update the related settings there.
