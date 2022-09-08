#pragma once
#include "../network/network.hpp"
#include "../network/network_defs.hpp"
#include "../utils/console_renderer.hpp"
// 
#define CHAR_SPACE 0x20
//.
#define CHAR_PERIOD 0x2e

//*
#define CHAR_ASETERIK 0x2a

//:
#define CHAR_COLON 0x3a

//-
#define CHAR_MINUS 0x2d

//+
#define CHAR_PLUS 0x2b

//O
#define CHAR_O 0x4f

//=
#define CHAR_EQ 0x3d
//@
#define CHAR_AT 0x40
//#
#define CHAR_HASHTAG 0x23




namespace NNVis
{

	const char charset[] = {
		CHAR_SPACE,
		CHAR_PERIOD,
		CHAR_ASETERIK,
		CHAR_COLON,
		CHAR_MINUS,
		CHAR_PLUS,
		CHAR_O,
		CHAR_EQ,
		CHAR_AT,
		CHAR_HASHTAG

	};
	class NetworkVisualizer
	{

		CLIRenderer::CRenderer renderer;
		NN::Network* network_ptr;

		char GetCharFromActivation(NN::activation_t activation);
	public:
		NetworkVisualizer(NN::Network* network_ptr);
		void Render();
	};
}