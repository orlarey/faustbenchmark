//----------------------------------------------------------
// name: "fm"
//
// Code generated with Faust 2.72.15 (https://faust.grame.fr)
//----------------------------------------------------------

/* link with  */
#include <math.h>
#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#ifndef FAUSTCLASS
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

class mydsp : public dsp
{
private:
	class SIG0
	{
	private:
		int fSampleRate;
		int iVec2State; // Single Delay
		// Recursion delay iVeeec14 is of type kMonoDelay
		// While its definition is of type kZeroDelay
		int iVeeec14State; // Mono Delay
	public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate)
		{
			fSampleRate = sample_rate;
			iVec2State = 0;
			iVeeec14State = 0;
		}
		void fill(int count, float output[])
		{
			int iVec2[2];
			int iVeeec14;
			int fullcount = count;
			for (int index = 0; index < fullcount; index += 32)
			{
				int count = min(32, fullcount - index);
				iVec2[1] = iVec2State;
				iVeeec14 = iVeeec14State;
				for (int i = 0; i < count; i++)
				{
					iVec2[0] = 1;
					iVeeec14 = ((iVec2[1] + iVeeec14) % 65536);
					output[i] = sinf((9.58738e-05f * float(iVeeec14)));
					// post processing
					iVec2[1] = iVec2[0];
				}
				iVec2State = iVec2[1];
				iVeeec14State = iVeeec14;
				output += 32;
			}
		}
	};

	FAUSTFLOAT fbutton0;
	float fVec0State; // Single Delay
	float fConst0;	  // step: 10
	float fConst1;	  // step: 11
	float fConst2;	  // step: 13
	int iVec1State;	  // Single Delay
	// Recursion delay fVeeec0 is of type kMonoDelay
	// While its definition is of type kZeroDelay
	float fVeeec0State; // Mono Delay
	float fConst3;		// step: 25
	FAUSTFLOAT fslider0;
	// Recursion delay fVeeec5 is of type kMonoDelay
	// While its definition is of type kZeroDelay
	float fVeeec5State; // Mono Delay
	FAUSTFLOAT fslider1;
	float fConst4; // step: 50
	// Recursion delay fVeeec7 is of type kMonoDelay
	// While its definition is of type kZeroDelay
	float fVeeec7State; // Mono Delay
	FAUSTFLOAT fslider2;
	// Recursion delay fVeeec10 is of type kMonoDelay
	// While its definition is of type kZeroDelay
	float fVeeec10State; // Mono Delay
	// Recursion delay fVeeec9 is of type kMonoDelay
	// While its definition is of type kZeroDelay
	float fVeeec9State; // Mono Delay
	static float ftbl0[65536];
	// Recursion delay fVeeec3 is of type kMonoDelay
	// While its definition is of type kZeroDelay
	float fVeeec3State; // Mono Delay
	int fSampleRate;

public:
	virtual void metadata(Meta *m)
	{
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/tabulateNd", "Copyright (C) 2023 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/version", "1.15.0");
		m->declare("filename", "fm.dsp");
		m->declare("interface", "SmartKeyboard{  'Number of Keyboards':'1',  'Keyboard 0 - Number of Keys':'1',  'Keyboard 0 - Piano Keyboard':'0',  'Keyboard 0 - Static Mode':'1',  'Keyboard 0 - Send X':'1',  'Keyboard 0 - Send Y':'1' }");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.8.0");
		m->declare("name", "fm");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.5.1");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "1.5.0");
		m->declare("synths.lib/fm:author", "Romain Michon");
		m->declare("synths.lib/name", "Faust Synthesizer Library");
		m->declare("synths.lib/version", "1.1.0");
	}

	virtual int getNumInputs() { return 0; }
	virtual int getNumOutputs() { return 1; }
	static void classInit(int sample_rate)
	{
		SIG0 sig0;
		sig0.init(sample_rate);
		sig0.fill(65536, ftbl0);
	}
	virtual void instanceConstants(int sample_rate)
	{
		fSampleRate = sample_rate;
		fConst0 = min(1.92e+05f, max(1.0f, float(fSampleRate))); // step: 10
		fConst1 = (44.1f / fConst0);							 // step: 11
		fConst2 = (1.0f - fConst1);								 // step: 13
		fConst3 = (1.0f / fConst0);								 // step: 25
		fConst4 = (4.41e+04f / fConst0);						 // step: 50
	}
	virtual void instanceResetUserInterface()
	{
		fbutton0 = 0.0;
		fslider0 = 0.0f;
		fslider1 = 0.0f;
		fslider2 = 1.0f;
	}
	virtual void instanceClear()
	{
		fVec0State = 0;
		iVec1State = 0;
		fVeeec0State = 0;
		fVeeec5State = 0;
		fVeeec7State = 0;
		fVeeec10State = 0;
		fVeeec9State = 0;
		fVeeec3State = 0;
	}
	virtual void init(int sample_rate)
	{
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	virtual void instanceInit(int sample_rate)
	{
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	virtual mydsp *clone()
	{
		return new mydsp();
	}
	virtual int getSampleRate()
	{
		return fSampleRate;
	}
	virtual void buildUserInterface(UI *ui_interface)
	{
		ui_interface->openVerticalBox("fm");
		ui_interface->addButton("gate", &fbutton0);
		ui_interface->declare(&fslider2, "acc", "0 0 -10 0 10");
		ui_interface->addHorizontalSlider("res", &fslider2, 1.0f, 0.0f, 2.0f, 0.01f);
		ui_interface->addHorizontalSlider("x", &fslider0, 0.0f, 0.0f, 1.0f, 0.01f);
		ui_interface->addHorizontalSlider("y", &fslider1, 0.0f, 0.0f, 1.0f, 0.01f);
		ui_interface->closeBox();
	}
	virtual void compute(int count, FAUSTFLOAT *RESTRICT *input, FAUSTFLOAT *RESTRICT *output)
	{
		float fSlow0 = float(fbutton0); // step: 3
		float fVec0[2];
		float fSlow1 = (fConst1 * fSlow0); // step: 12
		int iVec1[2];
		float fVeeec0;
		int iSlow2 = (fSlow0 == 0.0f);							// step: 29
		float fSlow3 = ((4.2e+02f * float(fslider0)) + 8e+01f); // step: 38
		float fVeeec5;
		float fSlow4 = (fConst4 * float(fslider1)); // step: 51
		float fVeeec7;
		float fSlow5 = (fConst1 * float(fslider2)); // step: 57
		float fVeeec10;
		float fVeeec9;
		float fVeeec3;
		int fullcount = count;
		for (int index = 0; index < fullcount; index += 32)
		{
			int count = min(32, fullcount - index);
			FAUSTFLOAT *output0 = &output[0][index]; // Zone 3
			fVec0[1] = fVec0State;
			iVec1[1] = iVec1State;
			fVeeec0 = fVeeec0State;
			fVeeec5 = fVeeec5State;
			fVeeec7 = fVeeec7State;
			fVeeec10 = fVeeec10State;
			fVeeec9 = fVeeec9State;
			fVeeec3 = fVeeec3State;
			for (int i = 0; i < count; i++)
			{
				fVec0[0] = fSlow0;
				iVec1[0] = 1;
				fVeeec0 = (fSlow1 + (fConst2 * fVeeec0));
				int iTemp0 = (1 - iVec1[1]);						   // step: 23
				float fTemp1 = float(((fSlow0 == fVec0[1]) | iSlow2)); // step: 31
				fVeeec5 = ((fSlow3 * (1.0f - (0.999f * fTemp1))) + (0.999f * (fTemp1 * fVeeec5)));
				float fTemp2 = fVeeec5; // step: 45
				fVeeec7 = (fSlow4 + (fConst2 * fVeeec7));
				fVeeec10 = (fSlow5 + (fConst2 * fVeeec10));
				float fTemp3 = ((iTemp0) ? 0.0f : (fVeeec9 + (fConst3 * (fTemp2 * fVeeec10)))); // step: 66
				fVeeec9 = (fTemp3 - floorf(fTemp3));
				float fTemp4 = ((iTemp0) ? 0.0f : (fVeeec3 + (fConst3 * (fTemp2 + (fVeeec7 * ftbl0[max(0, int(min(int(int((65536.0f * fVeeec9))), 65535)))]))))); // step: 94
				fVeeec3 = (fTemp4 - floorf(fTemp4));
				output0[i] = (FAUSTFLOAT)((0.5f * (fVeeec0 * ftbl0[max(0, int(min(int(int((65536.0f * fVeeec3))), 65535)))]))); // Zone Exec Code
				// post processing
				iVec1[1] = iVec1[0];
				fVec0[1] = fVec0[0];
			}
			fVec0State = fVec0[1];
			iVec1State = iVec1[1];
			fVeeec0State = fVeeec0;
			fVeeec5State = fVeeec5;
			fVeeec7State = fVeeec7;
			fVeeec10State = fVeeec10;
			fVeeec9State = fVeeec9;
			fVeeec3State = fVeeec3;
		}
	}
};

float mydsp::ftbl0[65536];
