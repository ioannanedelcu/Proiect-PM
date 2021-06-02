# FM Transmitter
  Proiectul presupune crearea unui dispozitiv portabil de transmisie FM care primeste input audio prin mufa jack (de ex de la telefon/tableta) si transmite semnalul audio pe o frecventa radio aleasa de utilizator. Frecventa curenta va fi afisata pe un ecran LCD, iar alegerea sa se va face cu ajutorul unor potentiometre.
  La porinirea dispozitivului, pe ecran se va afisa un mesaj de WELCOME, timp in care se realizeaza initializarea modulului FM pe frecventa default (90 MHz). Dupa aproximativ 5 secunde, mesajul anterior dispare, iar pe LCD utilizatorul va putea vedea frecventa curenta. Pentru modificarea acesteia se vor folosi cele doua potentiometre de 50k, unul pentru partea intreaga (cu valori cuprinse intre 87 si 108 MHz) si celalat pentru partea zecimala (intre 0 si 10). Daca dispozitivul primeste input audio, acesta va putea fi auzit pe un aparat de radio extern (cum esre cel de la masina) aflat in imediata apropiere, pe frecventa setata (si afisata pe ecran). Pentru a mari raza de broadcast am lipit modulului FM si o mica antena. Cel de-al treilea potentiometru are rolul de a fixa luminozitatea ecranului LCD, functionalitate foarte utila daca se conduce pe timp de noapte.
  
  ### Listă de piese:
    * Arduino UNO
    * Breadboard
    * Modul FM V 2.0
    * Ecran Nokia 5110 85×48
    * Potentiometre
    * Rezistente
    * Fire mama-tata, tata-tata
  ## Schema electrica:
![image](https://user-images.githubusercontent.com/48175616/120454380-7fb7d280-c39c-11eb-810b-3af2b91d7502.png)

  ## Software design:
  Mediul de dezvoltare folosit a fost Arduino IDE. \
  Biblioteci folosite in implementare:
  + PCD8544.h (pentru folosirea ecranului LCD Nokia 5110 - interfata SPI)
  + FMTX.h (pentru folosirea modulului FM - interfata I2C)
    
  Principalele variabile utilizate:
  + lcd - obiectul LCD Nokia 5110 folosit pe parcursul programului
  + channel - canalul curent afisat pe LCD si transmis modulului FM
  + pot_read - valoarea analogica data de primul potentiometru (partea intreaga a frecventei)
  + freq_max, freq_min - limitele frecventei
  + mapping_reading - maparea valorii data de potentiometru in limitele frecventei
  + current_reading - valoarea curenta a frecventei (pentru a verifica daca s-a produs vreo schimbare)

In functia de setup se seteaza pinii A0 si A1 (la care sunt conectati cele doua potentiometre) pe modul INPUT si se porneste lcd-ul. Se afiseaza apoi pe acesta un mesaj de Welcome care va disparea dupa 5 secunde, timp in care se realizeaza si initializarea modulului FM pe frecventa default (90 MHz), respectiv Europa. In functia `loop` se citesc folosind `analogRead` valorile celor doua potentiometre si se realizeaza conversia acestora in limitele frecventei folosind functiile `map` si `constrain`. Daca valorile nou citite difera de vechile valori curente, se calculeaza noua frecventa, care se trimite ca parametru functiei `fmtx_set_freq`, urmand sa se faca astfel update la nivelul modulului FM. De asemenea, noile valori vor fi afisate si pe ecranul LCD, conform functiei auxiliare `lcd_freq`. 

Link demo: https://www.youtube.com/watch?v=XNFzS8EmZVw


