package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	// herna slucka / game loop
	for true {
		// nazov hry
		println("-----------------------------------------")
		println(" K A M E N - P A P I E R - N O Z N I C E")
		println("-----------------------------------------\n")

		println("Kamen - Papier - Noznice")
		println("  1        2        3\n")

		print("Vyber: ")
		var hrac int
		fmt.Scanln(&hrac)
		print("\n")

		// zaciname od 0
		hrac -= 1

		// vykreslime vybranu volbu hraca
		draw(hrac)

		// vygenerujeme nahodne cislo - volbu pocitaca
		// zapneme generator nahodnych cisel
		rand.Seed(time.Now().UnixNano())
		var pocitac int
		pocitac = rand.Intn(2)
		print("    vs.")
		draw(pocitac)
		println("\n")

		// zisitme, kto je vitaz a ohlasime to
		if winner(hrac, pocitac) == 1 {
			println("Vyhral si! 🏆 Gratulujem. 🎉\n")
		} else if winner(hrac, pocitac) == 0 {
			println("Lutujem, pocitac💻 ta porazil 😟\n")
		} else {
			println("Remiza... 😐\n")
		}

		// opytame sa hraca, ci chce hrat znova
		print("Chces este zahrat? ( a | n ) ")
		var hra string
		fmt.Scanln(&hra)
		if hra == "n" {
			break
		}

	}
}

func draw(volba int) {
	if volba == 0 {
		print("   🗻")
	} else if volba == 1 {
		print("   📄")
	} else {
		print("   ✂")
	}
}

func winner(hrac int, pocitac int) int {
	// kamen vs. noznice
	if hrac == 0 && pocitac == 2 {
		return 1
	} else if hrac == 2 && pocitac == 0 { // kamen vs. noznice
		return 0
	} else if hrac == 1 && pocitac == 0 { // papier vs. kamen
		return 1
	} else if hrac == 0 && pocitac == 1 { // kamen vs. papier
		return 0
	} else if hrac == 2 && pocitac == 1 { // noznice vs. papier
		return 1
	} else if hrac == 1 && pocitac == 2 { // papier vs. noznice
		return 0
	}

	// SPECIALNY PRIPAD - ak je remiza
	return -1
}
