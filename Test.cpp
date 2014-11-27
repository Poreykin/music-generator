#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "DebugIO.h"
#include "Instrument.h"
#include "Track.h"
#include "Test.h"

void testADSR()
{
	Instrument unknown(0.5, 0.5, 0.5, 0.5);
	double answers[] = {0.0, 0.2, 0.4, 0.6, 0.8, 1.0, 0.9, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3, 0.2, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
	for (int i = 0; i <= 20; ++i)
		if (fabs(unknown.ADSR(440, (double) i / 10.0, 1.0) - answers[i]) >= 0.000001)
			fprintf(stderr, "ADSR(%d) = %f (right answer is %f)\n", i, unknown.ADSR(440, (double) i / 10.0, 1.0), answers[i]);
	return;
}

void testInstrument()
{
	std::string testName;
	std::cin>>testName;

	Instrument instrument = scanInstrument(&std::cin);

	std::vector<std::pair<Note, double> > Melody(1, std::pair<Note, double>(Note(9, 1.0, 25), 0));

	Track melodyTrack(Melody, instrument);
	melodyTrack.normalize();
	
	std::ofstream outputFile1(testName + ".txt", std::ofstream::out);
	printInstrument(&outputFile1, instrument);

	//std::ofstream outputFile2(testName + " sample.wav", std::ofstream::binary);
	melodyTrack.drop(&(testName + " sample.wav")[0]);
}

void testPiano()
{
	std::string testName;
	std::cin>>testName;

	Piano piano = scanPiano(&std::cin);

	std::vector<std::pair<Note, double> > Melody(1, std::pair<Note, double>(Note(9, 0.003, 25), 0));

	Track melodyTrack(Melody, piano);
	melodyTrack.normalize();
	
	std::ofstream outputFile1(testName + ".txt", std::ofstream::out);
	printInstrument(&outputFile1, piano);

	//std::ofstream outputFile2(testName + " sample.wav", std::ofstream::binary);
	melodyTrack.drop(&(testName + " sample.wav")[0]);
}
