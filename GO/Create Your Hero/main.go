package main

import "fmt"

func main() {

	/* V Y T V O R   S I   H R D I N U
	  ---------------------------------
	   nauč sa: - premenné
				- dátové typy
				- výpis do terminálu
	*/

	// vytvoríme si hrdinu - Ninja
	var hero string = "Ninja"
	// premenná typu string
	// string / reťazec = text, slovo...veta

	// dáme hrdinovi zbraň
	var weapon string = "Katana"
	// premenné určujeme kľúčovým slovíčkom "var", potom následuje názov premennej a typ
	// var [nazov] string = "tu napisem text"

	// určíme hrdinov level
	var level int = 36
	// premenná typu int
	// int (integer) / celé číslo = 1, 2, 3, ... 1000, ...
	// var [nazov] int = 9

	// hrdinovi priradíme stats
	// ďalší spôsob deklarácie premennej je cez :=
	// [názov] := 10  /  [názov] := "text"
	health := 60
	damage := 20
	speed := 100

	// nastavíme, či je hrdina záporák
	var evil bool = false
	// premenná typu bool
	// boolean = pravda / nepravda <=> 1 / 0

	/* VÝPIS
	   - na výpis používame základný balíček fmt (format)
	   - základné funkcie:
	       * fmt.Print("Vypisem text") - vypíše do jedného riadku
		   * fmt.Println("Vypisem a skocim do noveho riadku") - po výpise zariadkuje
		   * fmt.Printf("Vypisem string 'hero': %s", hero) - slúži na výpis hodnôt z premenných
		          >> %s - výpis reťazca
				  >> %d - výpis int
				  >> %f - výpis float
				  >> %v - výpis základného formátu (bool)
	*/

	fmt.Println()
	fmt.Printf("%s,", hero)
	fmt.Printf(" lvl %d\n", level)
	fmt.Println("--------------")
	fmt.Printf("Weapon: %s\n", weapon)
	fmt.Printf("Evil: %v\n", evil)
	fmt.Println("--------------")
	fmt.Printf("HP: %d 💖\n", health)
	fmt.Printf("DMG: %d ⚔\n", damage)
	fmt.Printf("SPD: %d ⚡\n", speed)
	fmt.Println()

	// Teraz si vytvor vlastného hrdinu,
	// napr. Warrior ⚔, Juggernaut 🛡, Archer 🏹, Soldier 🔫, Mage ✨

}
