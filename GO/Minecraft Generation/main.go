package main

import (
	"math/rand"
	"time"
)

func main() {

	// 🌱🌱🌱🌱🌱🌱🌱🌱🌱🌱🌱🌱🌱🌱🌱🌱   1 layer of grass
	// 🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫
	// 🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫   3-5 layers
	// 🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫       of dirt
	// 🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫🟫
	// 🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️
	// 🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️
	// 🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️                                      20 LAYERS IN TOTAL
	// 🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️
	// 🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️
	// 🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️
	// 🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️
	// 🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️
	// 🎛️🎛️💎🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️💎🎛️   -,
	// 🎛️🎛️🎛️🎛️💎🎛️🎛️🎛️💎🎛️🎛️🎛️🎛️🎛️🎛️🎛️    |
	// 🎛️💎🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️💎🎛️🎛️🎛️    |-> 4 layers of few diamonds
	// 🎛️🎛️🎛️🎛️💎🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️   _!
	// 🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️
	// 🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️🎛️
	// 🌑🌑🌑🌑🌑🌑🌑🌑🌑🌑🌑🌑🌑🌑🌑🌑   1 layer of bedrock

	var world [20][16]string

	// random number generator
	rand.Seed(time.Now().UnixNano())

	//  3 / 4 layers of dirt randomly chosen
	var dirtLayers int = 3 + rand.Intn(2)

	// move in array by rows
	for r := 0; r < 20; r++ {
		// move in array by columns
		for c := 0; c < 16; c++ {
			// grass
			if r == 0 {
				world[r][c] = "🌱"
			} else if r >= 1 && r <= dirtLayers { // dirt layer
				world[r][c] = "🟫"
			} else if r == dirtLayers+1 || r == dirtLayers+2 { // transition between dirt and stone layer
				var dirt int = rand.Intn(2) // generates numbers 0,1
				if dirt == 0 {              // if it generates 0 = dirt is generated (1/2 chance)
					world[r][c] = "🟫"
				} else {
					world[r][c] = "🎛️"
				}
			} else if r >= 13 && r <= 16 { // diamond level
				// diamond random generation
				var diamond int = rand.Intn(8) // generates numbers 0, 1, 2, 3, 4, 5, 6, 7
				if diamond == 0 {              // if it generates 0 = diamond is generated (1/8 chance)
					world[r][c] = "💎"
				} else {
					world[r][c] = "🎛️"
				}
			} else {
				world[r][c] = "🎛️" // everything else is stone
			}

			// bedrock
			if r == 19 {
				world[r][c] = "🌑"
			}
		}
	}

	// print our world
	for r := 0; r < 20; r++ {
		for c := 0; c < 16; c++ {
			print(world[r][c])
		}
		println()
	}

	// to prevent ending program
	// fmt.Scanln()

}
