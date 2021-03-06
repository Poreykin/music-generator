#include <cassert>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include "DebugIO.h"
#include "Note.h"
#include "Track.h"

void printNote(std::ostream* outputFile, const Note& note)
{
	(*outputFile)<<note.getFrequency()<<" "<<note.getDuration()<<" "<<note.getVolume();
}

void printMode(std::ostream* outputFile, const Mode& mode)
{
	if (mode == MAJOR)
		(*outputFile)<<"MAJOR";
	if (mode == MINOR)
		(*outputFile)<<"MINOR";
}

void printChord(std::ostream* outputFile, const Chord& chord)
{
	printNote(outputFile, chord.getNote());
	(*outputFile)<<" ";
	printMode(outputFile, chord.getMode());
}

void printNoteSequence(std::ostream* outputFile, const std::vector<std::pair<Note, double> >& NoteSequence)
{
	int SequenceLength = NoteSequence.size();
	for (int i = 0; i < SequenceLength; ++i) {
		printNote(outputFile, NoteSequence[i].first);
		(*outputFile)<<" "<<NoteSequence[i].second<<"\n";
	}
}

void printChordSequence(std::ostream* outputFile, const std::vector<std::pair<Chord, double> >& ChordSequence)
{
	int sequenceLength = ChordSequence.size();
	for (int i = 0; i < sequenceLength; ++i) {
		printChord(outputFile, ChordSequence[i].first);
		(*outputFile)<<" "<<ChordSequence[i].second<<"\n";
	}
}

void printInstrument(std::ostream* outputFile, const Instrument& instrument)
{
	std::map<double, double> harmonics = instrument.getHarmonics();
	(*outputFile)<<harmonics.size()<<"\n";
	for (auto harmonic : harmonics)
		(*outputFile)<<harmonic.first<<" "<<harmonic.second<<"\n";
	(*outputFile)<<instrument.getAttackTime()<<" "<<
			instrument.getDecayTime()<<" "<<
			instrument.getSustainLevel()<<" "<<
			instrument.getReleaseTime()<<"\n";
}

void printTrack(std::ostream* outputFile, const Track& track)
{
	int trackLength = track.getLength();
	for (int i = 0; i < trackLength; ++i) {
		assert(fabs(track.getValue(i)) <= MAX_AMPLITUDE);
		(*outputFile)<<track.getValue(i)<<"\n";
	}
}

std::vector<std::pair<Note, double> > scanNoteSequence(std::istream* inputFile)
{
	int numberOfNotes;
	(*inputFile)>>numberOfNotes;

	std::vector<std::pair<Note, double> > noteSequence;
	for (int i = 0; i < numberOfNotes; ++i)
	{
		int Frequency;
		double Duration, Amplitude, Position;
		(*inputFile)>>Frequency>>Duration>>Amplitude>>Position;
	        noteSequence.push_back(std::pair<Note, double>(Note(Frequency, Duration, Amplitude), Position));
	}

	return noteSequence;
}

Instrument scanInstrument(std::istream* inputFile)
{
	int numberOfHarmonics;
	(*inputFile)>>numberOfHarmonics;

	std::map<double, double> harmonics;
	for (int i = 0; i < numberOfHarmonics; ++i)
	{
		double harmonic, harmonicIndex;
		(*inputFile)>>harmonic>>harmonicIndex;
		harmonics[harmonic] = harmonicIndex;
	}	

	double A, D, S, R;
	(*inputFile)>>A>>D>>S>>R;

	return Instrument(Harmonics(harmonics, 1.0), A, D, S, R);
}

Piano scanPiano(std::istream* inputFile)
{
	int numberOfHarmonics;
	(*inputFile)>>numberOfHarmonics;

	std::map<double, double> harmonics;
	for (int i = 0; i < numberOfHarmonics; ++i)
	{
		double harmonic, harmonicIndex;
		(*inputFile)>>harmonic>>harmonicIndex;
		harmonics[harmonic] = harmonicIndex;
	}	

	return Piano(Harmonics(harmonics, 1.0));
}

windInstrument scanWindInstrument(std::istream* inputFile)
{
	int numberOfHarmonics;
	(*inputFile)>>numberOfHarmonics;

	std::map<double, double> harmonics;
	for (int i = 0; i < numberOfHarmonics; ++i)
	{
		double harmonic, harmonicIndex;
		(*inputFile)>>harmonic>>harmonicIndex;
		harmonics[harmonic] = harmonicIndex;
	}	

	double A, D, S, R;
	(*inputFile)>>A>>D>>S>>R;

	return windInstrument(Harmonics(harmonics, 1.0), A, D, S, R);
}
