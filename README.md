# MFC GDI Lab Exercises (Računarska grafika)

Ovaj repozitorijum sadrži rešenja laboratorijskih vežbi iz predmeta **Računarska grafika**, rađenih u programskom jeziku C++ korišćenjem **MFC (Microsoft Foundation Classes)** i **GDI (Graphics Device Interface)** alata u Visual Studio okruženju.

## 🛠 Tehnologije i alati
* **Jezik:** C++
* **Okruženje:** Visual Studio 2026
* **Tehnologija:** MFC / Win32 API / GDI (Graphics Device Interface)

## 📌 Kratak opis urađenog rada (LV01)
Projekat demonstrira osnove rada sa GDI grafičkim kontekstom (`CDC`) unutar MFC `CView` arhitekture:
- **Upravljanje kontekstom uređaja (`CDC`):** Korišćenje `CDC` klase i osnovnih GDI objekata (`CPen`, `CBrush`) za iscrtavanje geometrijskih figura i Tangram slagalice bez funkcija automatskog ispunjavanja (`FloodFill`).
- **Interakcija sa korisnikom:** Rukovanje događajima sa tastature (`OnChar` / `OnKeyDown`) radi dinamičke kontrole prikaza i uključivanja/isključivanja pozadinske mreže (grida).
- **Geometrijske transformacije i crtanje:** Implementacija funkcija za iscrtavanje proizvoljnih i pravilnih poligona pomoću trigonometrijskih funkcija.

## 🚀 Pokretanje projekta
1. Klonirajte repozitorijum ili preuzmite ZIP fajl.
2. Otvorite `.sln` fajl rešenja (Solution) u **Visual Studio 2026**.
3. Podesite konfiguraciju na **Debug / Release (x86 / x64)**.
4. Pritisnite **F5** da kompajlirate i pokrenete aplikaciju.
