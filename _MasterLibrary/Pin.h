#ifndef PIN_H_
#define PIN_H_

#define DEFINE_PIN(PINNAME, PORT, BIT) \
	class _Pin##PINNAME \
	{ \
	public: \
		inline void SetDirIn() { SETLOW(PORT##DIR, BIT); } \
		inline void SetDirOut() { SETHIGH(PORT##DIR, BIT); } \
		inline void SetDir(PINDIR dir) { if (dir == PININPUT) SetDirIn(); else SetDirOut(); } \
\
		inline void SetOutLow() { SETLOW(PORT##OUT, BIT); } \
		inline void SetOutHigh() { SETHIGH(PORT##OUT, BIT); } \
		inline void SetOut(PINVALUE val) {if (val == PINLOW) SetOutLow(); else SetOutHigh(); } \
		inline void Toggle() { TOGGLE(PORT##OUT, BIT); } \
\
		inline void EnablePinResistance() { SETHIGH(PORT##REN, BIT); } \
		inline void DisablePinResistance() { SETLOW(PORT##REN, BIT); } \
\
		inline void EnableInt() { SETHIGH(PORT##IE, BIT); } \
		inline void DisableInt() { SETLOW(PORT##IE, BIT); } \
		inline void EnableIntFromLowToHigh() { SETLOW(PORT##IES, BIT); } \
		inline void EnableIntFromHighToLow() { SETHIGH(PORT##IES, BIT); } \
		inline void ClearIntFlag() { SETLOW(PORT##IFG, BIT); } \
\
		inline void InitPullupButtonFromLowToHigh() \
			{ \
				SetOutHigh(); \
				EnablePinResistance(); \
				EnableIntFromHighToLow(); \
				ClearIntFlag(); \
				EnableInt(); \
			} \
\
	} PINNAME;

#endif /* PIN_H_ */
