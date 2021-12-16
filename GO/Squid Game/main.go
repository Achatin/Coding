package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {

	// random number generator
	rand.Seed(time.Now().UnixNano())

	players := 4
	round := 0
	// randomly generated trapped glass
	var trap int
	// displays current player 👩 / 👦 / 👨 / 👧
	var player string
	// your choice of path
	var choice int

	// stores previous position of the player to replace it with glass
	var prevPos []int

	prevPos = []int{0, 8}

	var Game [][]string

	// game title and rules
	fmt.Println()
	fmt.Println("------------------------------------------------")
	fmt.Println(" T H E   G L A S S   T I L E   G A M E   🔺🔴🔶")
	fmt.Println("------------------------------------------------")
	fmt.Println()
	fmt.Println("There are 8 pairs of glass tiles. Each pair contains \none tempered glass and one that will BREAK. Choose wisely!")
	fmt.Println()

	Game = [][]string{
		{"👨", "👩", " ", "🔳", "🔳", "🔳", "🔳", "🔳", "🔳", "🔳", "🔳", "🏁", " ", " ", " ", "1"},
		{"👧", "👦", " ", "🔳", "🔳", "🔳", "🔳", "🔳", "🔳", "🔳", "🔳", "🏁", " ", " ", " ", "2"},
	}

	fmt.Println(Game[0])
	fmt.Println(Game[1])

	// herna slucka / game loop
	for players > 0 && round < 9 {

		// chooses trapped glass - 0 = path 1, 1 = path 2
		// for all 8 glasses
		if round < 8 {
			trap = rand.Intn(2)
		} else { // after glass 8, there is no trap
			trap = -1
		}

		fmt.Print("Choose a path (1 | 2): ")
		fmt.Scanf("%d\n", &choice)
		fmt.Println()

		// chosen player
		if players == 4 {
			player = "👩"
		} else if players == 3 {
			player = "👦"
		} else if players == 2 {
			player = "👨"
		} else {
			player = "👧"
		}

		// player chooses path 1
		if choice == 1 {

			if trap == 0 { // if the glass is trapped
				// remove the player
				if players == 4 {
					Game[0][1] = "💀"
				} else if players == 3 {
					Game[1][1] = "💀"
				} else if players == 2 {
					Game[0][0] = "💀"
				} else {
					Game[1][0] = "💀"
				}
				// lose 1 plyer
				players -= 1
				// remove broken glass
				Game[0][3+round] = "❌"
			} else { // glass is safe
				if players == 4 {
					Game[0][1] = "💨"
				} else if players == 3 {
					Game[1][1] = "💨"
				} else if players == 2 {
					Game[0][0] = "💨"
				} else {
					Game[1][0] = "💨"
				}
				// put player on the position of the glass
				Game[0][3+round] = player
				// save the position to later replace it with 🔳
				prevPos[0] = 0
				prevPos[1] = 3 + round
			}
		} else { // if player chooses path 2
			if trap == 1 { // if the glass is trapped
				// remove the player
				if players == 4 {
					Game[0][1] = "💀"
				} else if players == 3 {
					Game[1][1] = "💀"
				} else if players == 2 {
					Game[0][0] = "💀"
				} else {
					Game[1][0] = "💀"
				}
				// lose 1 player
				players -= 1
				// remove glass
				Game[1][3+round] = "❌"
			} else { // if the glass is safe
				if players == 4 {
					Game[0][1] = "💨"
				} else if players == 3 {
					Game[1][1] = "💨"
				} else if players == 2 {
					Game[0][0] = "💨"
				} else {
					Game[1][0] = "💨"
				}
				// put the player on the position of the glass
				Game[1][3+round] = player
				// save the position to later replace it with 🔳
				prevPos[0] = 1
				prevPos[1] = 3 + round
			}
		}

		fmt.Println(Game[0])
		fmt.Println(Game[1])

		// replace the previous position with 🔳
		Game[prevPos[0]][prevPos[1]] = "🔳"

		round++
	}

	fmt.Println()

	// win
	if round == 9 {
		fmt.Println("Congratulations, you win! 🎉")
		if players == 1 {
			fmt.Printf("You've saved only %d player. 👼\n", players)
		} else {
			fmt.Printf("You've saved %d players. 👼\n", players)
		}
		fmt.Println()
	}
	// fail
	if players == 0 {
		fmt.Println("All players have been eliminated 💀")
		fmt.Println()
	}

}
