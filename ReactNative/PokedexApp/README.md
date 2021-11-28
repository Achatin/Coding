# Kôlnička Jeseň 2021 - Mobilná aplikácia pomocou React Native

Toto je oficiálny repozitár pre online workshop Kôlnička Jeseň 2021.

## Potrebné technológie a programy

Pri práci na workshope budeme využívať nasledujúce technológie a programy:

- [Node](https://nodejs.org/)
  - verzia LTS
- [Git Bash](https://git-scm.com/downloads)
  - pre Windows používateľov
  - Linux/Mac používateľom stačí pôvodný terminál
- [VSCode](https://code.visualstudio.com/)
  - preferovaný editor, avšak môžete využiť svoj obľúbený

## Spustenie projektu

Na začiatu si potrebujeme vyklonovať tento projekt. Môžete využiť ktorúkoľvek z HTTPS/SSH/GitHub CLI metód.

Do terminálu zadáme príkaz:

```bash
git clone git@github.com:bolyesz/kolnicka-fall-2021.git kolnicka
# alebo
git clone https://github.com/bolyesz/kolnicka-fall-2021.git kolnicka
```

Následne sa presunieme do novo vytvoreného priečinka pomocou tohto príkazu:

```bash
cd kolnicka
```

Keď sa nachádzame v priečinku, pred prvým spustením projektu potrebujeme nainštalovať všetky knižnice. V terminály spustíme nasledujúci príkaz:

```bash
npm install
```

Pre iOS je potrebné zadať príkaz:
```bash
cd ios && pod install && cd ..
```


Po inštalácií knižníc môžeme spustiť projekt pomocou Metra. Do terminálu zadáme príkaz:

```bash
npm run start
```

Ak všetko prebehlo úspešne, v príkazovom riadku by sme mali vidieť logo Metra a hlášku: "Welcome to Metro!"

Následne môžeme spustiť aplikáciu. V novom príkazovom okne zadáme príkaz:

iOS simulátor:

```bash
npm run ios
```

alebo Android emulátor:

```bash
npm run android
```

Po úspešnom spustení aplikácie, by sme na obrazovke mali vidieť nápis:

```
Ahoj Kôlnička!
```
