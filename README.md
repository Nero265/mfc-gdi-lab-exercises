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

## 📌 Kratak opis urađenog rada (LV02)
Vežba prikazuje rad sa **svetskim transformacijama** u GDI-ju. Cilj je iscrtavanje generičkog kaktusa (500x500 piksela):
- **Transformacije:** Implementirane funkcije `Translate`, `Scale` i `Rotate` koje množe tekuću transformacionu matricu (`ModifyWorldTransform`, mod `GM_ADVANCED`) sa leve ili desne strane.
- **Hijerarhijsko crtanje:** Svaki zglob kaktusa je koordinatni početak za grane koje iz njega izlaze (levo množenje, lokalni koordinatni sistem). Stanje transformacije se čuva i vraća pomoću `GetWorldTransform` / `SetWorldTransform`.
- **Metafajlovi:** Delovi kaktusa sa bodljama učitavaju se iz EMF metafajlova (`cactus_part.emf`, `cactus_part_light.emf`) i iscrtavaju sa `PlayMetaFile`, uz skaliranje širine prema broju grana.
- **Interakcija:** Taster `G` uključuje/isključuje mrežu, a svetliji delovi kaktusa rotiraju se tasterima `A`/`D` i `Q`/`E`.

> Napomena: EMF fajlovi moraju biti u radnom direktorijumu aplikacije (npr. folder projekta ili `Debug` / `x64\Debug`).

## 🚀 Pokretanje projekta
1. Klonirajte repozitorijum ili preuzmite ZIP fajl.
2. Otvorite `.sln` fajl rešenja (Solution) u **Visual Studio 2026**.
3. Podesite konfiguraciju na **Debug / Release (x86 / x64)**.
4. Pritisnite **F5** da kompajlirate i pokrenete aplikaciju.
