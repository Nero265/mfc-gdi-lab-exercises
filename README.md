# MFC GDI Lab Exercises (Računarska grafika)

Ovaj repozitorijum sadrži rešenja laboratorijskih vežbi iz predmeta **Računarska grafika**, rađenih u programskom jeziku C++ korišćenjem **MFC (Microsoft Foundation Classes)** i **GDI (Graphics Device Interface)** alata u Visual Studio okruženju.

## 🛠 Tehnologije i alati
* **Jezik:** C++
* **Okruženje:** Visual Studio (2022)
* **Tehnologija:** MFC / Win32 API / GDI (Graphics Device Interface)

## 📌 Kratak opis urađenog rada
Projekat demonstrira osnovne principe rada sa GDI alatima u okviru MFC `CView` arhitekture:
- **Upravljanje kontekstom uređaja (`CDC`):** Korišćenje `CDC` klase za iscrtavanje po radnoj površini prozora.
- **Optimizacija pozadine (`OnEraseBkgnd`):** Prevazilaženje podrazumevanog treperenja ekrana (flickering) i ručno bojenje pozadine prozora pomoću `CBrush` i `FillRect` funkcija u tamno sivu boju.
- **Interakcija sa korisnikom:** Rukovanje događajima sa tastature (`OnChar` / `OnKeyDown`) radi dinamičke kontrole prikaza (npr. uključivanje/isključivanje mreže - grida na ekranu).
- **Inicijalizacija i osvežavanje (`OnDraw` / `Invalidate`):** Dinamičko crtanje i osvežavanje sadržaja prozora u realnom vremenu.

## 🚀 Pokretanje projekta
1. Klonirajte repozitorijum ili preuzmite ZIP fajl.
2. Otvorite `.sln` fajl rešenja (Solution) u **Visual Studio 2022**.
3. Podesite konfiguraciju na **Debug / Release (x86 / x64)**.
4. Pritisnite **F5** da kompajlirate i pokrenete aplikaciju.
