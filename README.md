# Projekt-Graa
Ten projekt to klasyczna gra strzelanka 2D, stworzona za pomocą biblioteki SFML i języka C++. W grze gracz steruje samolotem, poruszając się w lewo i prawo oraz strzelając do przeciwników, którzy pojawiają się na górze ekranu. Celem gry jest zdobycie jak największej liczby punktów poprzez zestrzeliwanie wrogich statków.

Funkcje gry:

Sterowanie: Gracz może poruszać się w lewo i prawo za pomocą klawiszy strzałek oraz strzelać, naciskając spację.
Przeciwnicy: Wrogie statki generowane są losowo na górze ekranu i pozostają tam, aż zostaną zestrzelone.
Pociski: Gracz może strzelać pociskami, które poruszają się w górę ekranu.
Wynik: Wynik jest wyświetlany na górze ekranu i zwiększa się o jeden punkt za każdego zestrzelonego przeciwnika.
Menu: Gra zawiera menu główne z opcjami: "Start Game", "Load Game", "Settings" i "Exit". Menu ustawień pozwala na włączenie/wyłączenie muzyki oraz regulację głośności.
Zapis i wczytywanie gry: Gra pozwala na zapisanie aktualnego wyniku do pliku oraz jego wczytanie przy ponownym uruchomieniu.
Biblioteki i narzędzia:

Struktura projektu:

Gra.exe: Plik wykonywalny gry.
Menu: Moduł odpowiedzialny za wyświetlanie i obsługę menu głównego.
Player: Klasa odpowiedzialna za sterowanie samolotem gracza.
Enemy: Klasa odpowiedzialna za zarządzanie wrogimi statkami.
Bullet: Klasa odpowiedzialna za zarządzanie pociskami.
SettingsMenu: Moduł odpowiedzialny za wyświetlanie i obsługę menu ustawień.
Zasoby: Katalog zawierający grafiki, czcionki i muzykę używane w grze.

