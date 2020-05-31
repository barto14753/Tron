# Tron - projekt na przedmiot "Programowanie Imperatywne"

# Biblioteka
Do stworzenia projektu wykorzystałem CSFML, czyli binding popularnej biblioteki C++ - SFML.
# Środowisko
Projekt był tworzony na systemie Windows 8 z użyciem Visual Studio Comunnity 2019, i poniższa instrukcja 
uruchomienia będzie dotyczyć tego właśnie IDE.
# Pobranie i ustawienie
1. Pobranie/skopiowanie repozytorium: git clone https://github.com/barto14753/Tron
2. Pobranie bilioteki i wypakowanie biblioteki CSFML 2.5 : https://www.sfml-dev.org/download/csfml/
3. Otwarcie pobranego projektu.
4. Wejście w Widok/Właściwości "nazwa_projektu"
5. Ustawienie konfiguracji na Debug
6. C/C++ - zmienną "Dodatkowe katalogi plików nagłówkowych" ustawiamy na: "ścieżka_do_pobranej_biblioteki_csfml"/include 
7. Konsolidator/Ogólne - zmienną "Dodatkowe katalogi bibliotek" ustawiamy na: "ścieżka_do_pobranej_biblioteki_csfml"/lib/msvc
8. Konsolidator/Dane Wejściowe - dodajemy następujące "dodatkowe zależności": csfml-graphics.lib, csfml-window.lib

Link do filmiku z ustawieniami dla zwykłego SFML, procedura jest dość podobna : 
https://www.youtube.com/watch?v=YfMQyOw1zik

# Uruchomienie
Gra posiada menu z reaktywnymi przyciskami rozpoczęcia oraz zakończenia gry.
Gra polega na tym, że dwójaka graczy (sterowanie: ASDW i "strzałki") rysuje swoje "węże" i  stara się aby ich "głowy" nie zetknęły się z powierzchnią zajętą już przez przeciwnika, jego samego lub ścianę. Przegrywa ten, który pierwszy doprowadzi do takiej sytuacji. Po zakończonej rozgrywce pojawia się "ending screen" z informacją o zwycięzcy oraz przyciskiem "continue", które przekierowywuje do początkowego menu.

Krótki filmik z rozgrywką:
https://drive.google.com/file/d/1rQ8M7FJ_Fe_Sha0emH4vb3U1_EI8bomp/view?usp=sharing

