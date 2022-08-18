package main

import (
	"fmt"
	"math/rand"
	"time"

	"github.com/fogleman/gg"
)

// cube colors
// color, shade, tint
var red = []string{"#CC1B2B", "#B61826", "#E31E30"}
var blue = []string{"#9E73DA", "#8D66C2", "#B080F2"}
var white = []string{"#DADADA", "#C2C2C2", "#F2F2F2"}

// background colors
var bg = []string{"#04d89d", "#b5d389", "#ffa4d4"}

// special colors
var gold = []string{"04c333", "03ae2e", "04d939"}

func main() {
	for i := 0; i < 100; i++ {
		// RNG
		rand.Seed(time.Now().UnixNano())

		// CANVAS
		dc := gg.NewContext(4000, 4000)

		dc.SetHexColor(bg[ /*rand.Intn(len(bg))*/ 0])
		dc.Clear()

		// GENERATE
		generate(dc)

		dc.SavePNG(fmt.Sprintf("./output/[item #%d].png", i))
	}
}

func generate(dc *gg.Context) {

	schema := [][][]string{
		{ChooseColor(), ChooseColor(), ChooseColor(), ChooseColor()},
		{ChooseColor(), ChooseColor(), ChooseColor(), ChooseColor()},
	}

	//          ____
	//         / 0 /
	//    ____     ____
	//   / 1 /    / 2 /
	//       ____
	//      / 3 /

	// LEVEL1
	drawFull(dc, 1900, 1800, schema[0][0])

	if schema[0][1][0] == schema[1][1][0] && schema[0][1][0] == schema[0][3][0] {
		drawFull(dc, 1550, 2000, schema[1][1])
		drawLongTileHorizontalLeft(dc, 1550, 2000, schema[0][1])
		drawLongTileVertical(dc, 1550, 2000, schema[1][1])
	} else if schema[0][1][0] == schema[1][1][0] {
		drawFull(dc, 1550, 2000, schema[1][1])
		drawLongTileVertical(dc, 1550, 2000, schema[1][1])
	} else if schema[0][1][0] == schema[0][3][0] {
		drawFull(dc, 1550, 2000, schema[1][1])
		drawLongTileHorizontalLeft(dc, 1550, 2000, schema[0][1])
	} else {
		drawFull(dc, 1550, 2000, schema[0][1])
	}

	if schema[0][2][0] == schema[1][2][0] {
		drawFull(dc, 2250, 2000, schema[1][2])
		if schema[0][2][0] == schema[0][3][0] {
			drawLongTileHorizontalRight(dc, 2250, 2000, schema[0][2])
		}
		drawLongTileVertical(dc, 2250, 2000, schema[1][2])
	} else if schema[0][2][0] == schema[0][3][0] {
		drawFull(dc, 2250, 2000, schema[0][2])
		drawLongTileHorizontalRight(dc, 2250, 2000, schema[0][2])
	} else {
		drawFull(dc, 2250, 2000, schema[0][2])
	}

	// tile 3
	drawFull(dc, 1900, 2200, schema[0][3])
	if schema[0][3][0] == schema[1][3][0] {
		drawLongTileVertical(dc, 1900, 2200, schema[0][3])
	}

	// LEVEL 2
	// 0 - back
	if schema[1][0][0] == schema[1][1][0] && schema[1][0][0] == schema[1][2][0] {
		drawLongTileHorizontalRight(dc, 1900, 1400, schema[1][0])
		drawLongTileHorizontalLeft(dc, 1900, 1400, schema[1][0])
		drawLongTileHorizontalRight(dc, 1900, 1400, schema[1][0])
	} else if schema[1][0][0] == schema[1][1][0] {
		drawFull(dc, 1900, 1400, schema[1][0])
		drawLongTileHorizontalRight(dc, 1900, 1400, schema[1][0])
	} else if schema[1][0][0] == schema[1][2][0] {
		drawLongTileHorizontalLeft(dc, 1900, 1400, schema[1][0])
	} else if schema[1][0][0] != schema[1][1][0] && schema[1][0][0] != schema[1][2][0] {
		drawFull(dc, 1900, 1400, schema[1][0])
	}

	// 1 - left
	if schema[1][1][0] == schema[1][3][0] {
		drawLongTileHorizontalLeft(dc, 1550, 1600, schema[1][1])
	} else {
		drawFull(dc, 1550, 1600, schema[1][1])
	}
	// 2 - right
	drawFull(dc, 2250, 1600, schema[1][2])
	if schema[1][2][0] == schema[1][3][0] {
		drawLongTileHorizontalRight(dc, 2250, 1600, schema[1][2])
	}

	// 3 - front
	drawFull(dc, 1900, 1800, schema[1][3])
}

func ChooseColor() []string {
	rng := rand.Intn(3)
	switch rng {
	case 0:
		return red
	case 1:
		return blue
	case 2:
		return white
	}
	return red
}

func drawFull(dc *gg.Context, xPos float64, yPos float64, color []string) {
	dc.DrawRectangle(xPos-200, yPos, 300, 350)
	dc.SetHexColor(color[0])
	dc.Fill()
	dc.DrawRectangle(xPos+100, yPos, 300, 350)
	dc.SetHexColor(color[1])
	dc.Fill()
	dc.DrawRegularPolygon(3, xPos, yPos, 200, gg.Radians(30))
	dc.DrawRegularPolygon(3, xPos+200, yPos, 200, gg.Radians(-30))
	dc.SetHexColor(color[2])
	dc.Fill()

	// BOTTOM
	dc.DrawRegularPolygon(3, xPos, yPos+350, 200, gg.Radians(30))
	dc.SetHexColor(color[0])
	dc.Fill()
	dc.DrawRegularPolygon(3, xPos+200, yPos+350, 200, gg.Radians(-30))
	dc.SetHexColor(color[1])
	dc.Fill()
}

func drawLongTileVertical(dc *gg.Context, xPos float64, yPos float64, color []string) {
	drawFull(dc, xPos, yPos-350, color)
	drawFull(dc, xPos, yPos-400, color)
}

func drawLongTileHorizontalLeft(dc *gg.Context, xPos float64, yPos float64, color []string) {
	drawFull(dc, xPos, yPos, color)
	drawFull(dc, xPos+175, yPos+100, color)
	drawFull(dc, xPos+350, yPos+200, color)
}

func drawLongTileHorizontalRight(dc *gg.Context, xPos float64, yPos float64, color []string) {
	//drawFull(dc, xPos, yPos, color)
	drawFull(dc, xPos-297.5, yPos+170, color)
	drawFull(dc, xPos-350, yPos+200, color)
}
