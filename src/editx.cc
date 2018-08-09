//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\framewin.h>
#include <owl\static.h>
#include <owl\edit.h>
#include <owl\inputdia.h>
#include <owl\opensave.h>
#include <owl\validate.h>
#include <owl\slider.h>
#include <owl\radiobut.h>
#include <owl\groupbox.h>
#include <fstream.h>
#include <cstring.h>
#include "editx.rh"

#include "synthese.h"


int dummy() ;

char szProgramPath[_MAX_PATH] ;
int* h ;

// Control ids:
//
const int ID_EXAMPLE_EDIT       = 200;

// Message ids:
//
const int CN_UPDATE             = 300;

class TExampleEdit : public TEdit {
  public:
	 TExampleEdit(TWindow*        parent,
					  int             id,
					  const char far* text,
					  int x=200, int y=0, int w=2000, int h=1000,
					  UINT            textLen = EditTextLen + 1,
					  BOOL            multiline = TRUE,
					  TModule*        module = 0 )
		: TEdit(parent, id, text, x, y, w, h, textLen, multiline, module)
	 {
		LastCBOpStr = " ";
	 }

	 // override to setup 'FileData' structure.
	 //
	 void SetupWindow();

	 // override to update text fields.
	 //
	 void    CmEditCut();                   // CM_EDITCUT
	 void    CmEditCopy();                  // CM_EDITCOPY
	 void    CmEditPaste();                 // CM_EDITPASTE
	 void    CmEditDelete();                // CM_EDITDELETE
	 void    CmEditClear();                 // CM_EDITCLEAR
	 void    CmEditUndo();                  // CM_EDITUNDO
	 void    EvKeyDown(UINT key, UINT repeatCount, UINT flags);
	 void    EvLButtonDown(UINT modKeys, TPoint& point);

	 // Newly defined functions (not defined by base classes):
	 //
	 void SaveSelection(char* filnam, char* result) ;
	 char* Selection() ;
	 void NotifyParent(int notification);
	 void SaveText();
	 void SaveTextNoQuery(char* filnam) ;
	 void RestoreText();
	 void ChangeName(char* name) ;
	 char* GetFileName() ;
	 const string& GetLastCBOpStr() const {return LastCBOpStr;}

	 string                  LastCBOpStr;   // string value of last CB operation.
	 static const unsigned   EditTextLen;   // length of edit control text.

  private:
	 TOpenSaveDialog::TData  FileData;      // save/restore info.

  DECLARE_RESPONSE_TABLE(TExampleEdit);
};

DEFINE_RESPONSE_TABLE1(TExampleEdit, TEdit)
  EV_COMMAND(CM_EDITCUT,     CmEditCut),
  EV_COMMAND(CM_EDITCOPY,    CmEditCopy),
  EV_COMMAND(CM_EDITPASTE,   CmEditPaste),
  EV_COMMAND(CM_EDITDELETE,  CmEditDelete),
  EV_COMMAND(CM_EDITCLEAR,   CmEditClear),
  EV_COMMAND(CM_EDITUNDO,    CmEditUndo),
  EV_WM_KEYDOWN,
  EV_WM_LBUTTONDOWN,
END_RESPONSE_TABLE;

const unsigned TExampleEdit::EditTextLen   = 64000;

void
TExampleEdit::SetupWindow()
{
  TEdit::SetupWindow();
  FileData.Flags = OFN_FILEMUSTEXIST|OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT;
  FileData.SetFilter("Text files (*.TXT)|*.TXT|AllFiles (*.*)|*.*|");
//  FileData.FileName = "noname.txt" ;

}

//
// The next function group simply notifies the app to update the text fields
// then calls the base class version to do the actual processing.
//

void
TExampleEdit::CmEditCut()
{
  LastCBOpStr = "Cut";
  NotifyParent(CN_UPDATE);
  TEdit::CmEditCut();
  NotifyParent(CN_UPDATE);
  TEdit::CmEditCut();
}

void
TExampleEdit::CmEditCopy()
{
  LastCBOpStr = "Copy";
  NotifyParent(CN_UPDATE);
  TEdit::CmEditCopy();
}

void
TExampleEdit::CmEditPaste()
{
  LastCBOpStr = "Paste";
  NotifyParent(CN_UPDATE);
  TEdit::CmEditPaste();
  NotifyParent(CN_UPDATE);
}

void
TExampleEdit::CmEditDelete()
{
  LastCBOpStr = "Delete";
  NotifyParent(CN_UPDATE);
  TEdit::CmEditDelete();
  NotifyParent(CN_UPDATE);
}

void
TExampleEdit::CmEditClear()
{
  TEdit::CmEditClear();
  LastCBOpStr = "Clear";
  NotifyParent(CN_UPDATE);
}

void
TExampleEdit::ChangeName(char* name) {
	FileData.FileName = name ;
}

void
TExampleEdit::CmEditUndo()
{
  TEdit::CmEditUndo();
  LastCBOpStr = "Undo";
  NotifyParent(CN_UPDATE);
}

char* TExampleEdit::Selection()
{
	char* result ;
	uint start, end ;
	TEdit::GetSelection(start,end) ;
	result = new char[end-start+2] ;
	if (end > start) {
		TEdit::GetSubText(result,start,end) ;
		return(result) ; }
	else {
		return(NULL) ; } }

void TExampleEdit::SaveSelection(char* name,char* buffer)
{
	 ofstream    ofs(name, ios::out|ios::binary);
	 signed char 		 x ;
	 for (unsigned i = 0; i < strlen(buffer) && buffer[i]; i++) {
		x = buffer[i];
/*		switch (x) {
			 case 'ß': x = 225-256; break;
			 case 'ä': x = 132-256; break;
			 case 'ü': x = 129-256; break;
			 case 'ö': x = 148-256; break;
			 case 'Ä': x = 142-256; break;
			 case 'Ö': x = 153-256; break;
			 case 'Ü': x = 154-256; break; }
*/		 ofs.put (x); }
}



void
TExampleEdit::EvKeyDown(UINT key, UINT repeatCount, UINT flags)
{
  TEdit::EvKeyDown(key, repeatCount, flags);
  NotifyParent(CN_UPDATE);
}

void
TExampleEdit::EvLButtonDown(UINT modKeys, TPoint& point)
{
  TEdit::EvLButtonDown(modKeys, point);
  NotifyParent(CN_UPDATE);
}

//
// NotifyParent(). 'easy' method of notifing the parent of an event.
// Notifies immediately
void
TExampleEdit::NotifyParent(int notification)
{
  Parent->SendNotification(Attr.Id, notification, HWindow);
}

//
// SaveText().  Save text portion of edit control to a file.
//
void
TExampleEdit::SaveText()
{
  if (TFileSaveDialog(GetApplication()->MainWindow, FileData).Execute() == IDOK) {
	 ofstream    ofs(FileData.FileName, ios::out|ios::binary);
	 unsigned    maxLen = EditTextLen;
	 char far*   buffer = LockBuffer();
	 unsigned    size = min(maxLen, strlen(buffer));
	 char x ;
	 for (unsigned i = 0; i < size && buffer[i]; i++) {
		x = buffer[i];
/*		switch (x) {
			 case 'ß': x = 225-256; break;
			 case 'ä': x = 132-256; break;
			 case 'ü': x = 129-256; break;
			 case 'ö': x = 148-256; break;
			 case 'Ä': x = 142-256; break;
			 case 'Ö': x = 153-256; break;
			 case 'Ü': x = 154-256; break; }
*/		 ofs.put (x); }
	 UnlockBuffer(buffer);
  }
}

void
TExampleEdit::SaveTextNoQuery(char* filnam)
{
	 ofstream    ofs(filnam, ios::out|ios::binary);
	 unsigned    maxLen = EditTextLen;
	 char far*   buffer = LockBuffer();
	 unsigned    size = min(maxLen, strlen(buffer));
	 signed char 		 x ;
	 for (unsigned i = 0; i < size && buffer[i]; i++) {
		x = buffer[i];
/*		switch (x) {
			 case 'ß': x = 225-256; break;
			 case 'ä': x = 132-256; break;
			 case 'ü': x = 129-256; break;
			 case 'ö': x = 148-256; break;
			 case 'Ä': x = 142-256; break;
			 case 'Ö': x = 153-256; break;
			 case 'Ü': x = 154-256; break; }
*/		 ofs.put (x); }
	 UnlockBuffer(buffer);
}

//
// RestoreText().  Restore or read in text from a file.  Uses the first
// 'EditTextLen' characters from file.
//

char*
TExampleEdit::GetFileName()
{
	return(FileData.FileName) ;
}


void
TExampleEdit::RestoreText()
{
  if (TFileOpenDialog(GetApplication()->MainWindow, FileData).Execute() == IDOK) {
	 Clear();

	 ifstream    ifs(FileData.FileName);
	 char far*   buffer = LockBuffer(EditTextLen + 1);
	 unsigned int ux;
	 char x ;
    unsigned i ;

	 for (i = 0; i < EditTextLen && !ifs.eof(); i++) {
		buffer[i] = (char)ifs.get();
/* 		ux =  256 + buffer[i] ;
		switch (ux) {
			case 225: buffer[i] = 'ß'; break;
			case 132: buffer[i] = 'ä'; break;
			case 129: buffer[i] = 'ü'; break;
			case 148: buffer[i] = 'ö'; break;
			case 142: buffer[i] = 'Ä'; break;
			case 153: buffer[i] = 'Ö'; break;
			case 154: buffer[i] = 'Ü'; break;
			  }
*/		if (buffer[i] == '\n' && ifs.peek() != '\r') {
		  buffer[i] = '\r';
		  buffer[++i] = '\n';
		}
	 }
	 if (i)
		buffer[i-1] = 0;
	 UnlockBuffer(buffer, TRUE);
	 NotifyParent(CN_UPDATE);
  }
}

//----------------------------------------------------------------------------

class TEditWindow : public TFrameWindow {
  public:
	 TEditWindow(const char* title);

//	 void Close() ;

	 Synthese* synthi ;

	 void SetupWindow();

	 // message response functions
	 //
	 void CmUpdate() {UpdateTextFields();} // Edit control notification.
	 void CmInsertText();                  // insert text at char pos.
	 void CmDeleteSubText();               // delete subtext.
	 void CmDeleteLine();                  // delete line of text.
	 void CmSaveText();                    // save text in edit cntl.
	 void CmNewText() ;
	 void CmRestoreText();                 // restore from file into edit cntl.
	 void CmSynthesize() ;
	 void CmSynthesizeWithYourPitch() ;
	 void CmSynthesizeWithYourProsody() ;
	 void CmSymbolicsOnly() ;
    void CmOnwardFromSymbolics() ;
	 void CmNewVoice() ;
	 void CmNewSpeechRate() ;
	 void CmNewPitch() ;
	 void CmDefault() ;
	 void CmShowValues() ;
	 void CmPreprocess() ;
	 void CmAbout() ;
	 void CmHelp() ;
	 void CmStop() ;
    void CmChangeVoiceHorst() ;
    void CmChangeVoiceLioba() ;
    void CmSynthAsWav() ;
    void CmSynthFileAsWav() ;
    void CmSynthesizeFile() ;
    void give_changes() ;
    bool CanClose() ;

  private:
	 TExampleEdit*       EditCntl;         // edit control

	 TVSlider*				PitchSlider ;
	 TVSlider*				SpeechrateSlider ;
	 TVSlider*				PitchRangeSlider ;
	 TVSlider*				SpeechrateRangeSlider ;
	 TVSlider*				DeclinationSlider ;
	 TButton* 				SpeakButton ;
    TButton*				StopButton ;
    TButton*				ChangeSpeakerButton ;
    TGroupBox*				VoiceBox ;
    TRadioButton*			HorstButton ;
    TRadioButton*			LiobaButton ;
//    TScroller* 			MyScroller ;
//    TStatic*			 	FileNameField ;
/*	 TStatic*            NbrLinesText;     // text of number of lines.
	 TStatic*            CurLineNbrText;   // current line number.
	 TStatic*            CurLineText;      // current line, 1st N chars.
	 TStatic*            CurLineLenText;   // length of current line.
	 TStatic*            FirstVisibleLineText;  // line # of 1st visible line.
	 TStatic*            IsModifiedText;   // has edit control been modified.
	 TStatic*            LastCBOpText;     // last clipboard operation.
	 TStatic*            CurSelText;       // first N chars of selected text.
*/
	 static const unsigned   InputTextLen; // length of input text.
	 static const unsigned   FirstNChars;  // first n characters to display.

	 void  ResetTextFields();              // reset text fields to init values.
	 void  UpdateTextFields();             // updates from edit control

	 int                                   // read string from user.
	 InputString(char* prompt, char* s);

	 int                                   // read number from user
	 InputNumber(char* prompt, unsigned& n);

	 int defaultspeechrate, defaultpitch, defaultdeclination, defaultpitchrange, defaultfinallength, defaultaccentlength ;

    char* voices[2];
    int defaultvoice ;
    char* voicepath ;


  DECLARE_RESPONSE_TABLE(TEditWindow);
};

DEFINE_RESPONSE_TABLE1(TEditWindow, TFrameWindow)
  EV_CHILD_NOTIFY(ID_EXAMPLE_EDIT, CN_UPDATE, CmUpdate),
  EV_EN_VSCROLL(ID_EXAMPLE_EDIT, CmUpdate),
  EV_COMMAND(CM_INSERT_TEXT,         CmInsertText),
  EV_COMMAND(CM_DELETE_SUBTEXT,      CmDeleteSubText),
  EV_COMMAND(CM_DELETE_LINE,         CmDeleteLine),
  EV_COMMAND(CM_SAVE_TEXT,           CmSaveText),
  EV_COMMAND(CM_NEW_TEXT,				 CmNewText) ,
  EV_COMMAND(CM_RESTORE_TEXT,        CmRestoreText),
  EV_COMMAND(CM_SYNTHESIZE,			 CmSynthesize),
  EV_COMMAND(CM_SYNTH_AS_WAV,			 CmSynthAsWav),
  EV_COMMAND(CM_SYNTHESIZE_FILE,			 CmSynthesizeFile),
  EV_COMMAND(CM_SYNTH_FILE_AS_WAV,			 CmSynthFileAsWav),
/*  EV_COMMAND(CM_SYNTHESIZE_WITH_YOUR_PITCH,	CmSynthesizeWithYourPitch),
  EV_COMMAND(CM_SYNTHESIZE_WITH_YOUR_PROSODY,	CmSynthesizeWithYourProsody),
  EV_COMMAND(CM_SYMBOLICS_ONLY,		CmSymbolicsOnly),
  EV_COMMAND(CM_ONWARD_FROM_SYMBOLICS,	CmOnwardFromSymbolics), */
  EV_COMMAND(CM_NEW_VOICE,				 CmNewVoice),
  EV_COMMAND(CM_NEW_SPEECHRATE,      CmNewSpeechRate),
  EV_COMMAND(CM_NEW_PITCH,				 CmNewPitch),
  EV_COMMAND(CM_DEFAULT,				 CmDefault),
  EV_COMMAND(CM_SHOWVALUES,			 CmShowValues),
//  EV_COMMAND(CM_PREPROCESS,			 CmPreprocess),
  EV_COMMAND(CM_ABOUT,					 CmAbout),
  EV_COMMAND(CM_HELP,					 CmHelp),
  EV_COMMAND(CM_STOP,					 CmStop),
  EV_COMMAND(CM_SYNBUTTON,				 CmSynthesize),
  EV_COMMAND(CM_STOPBUTTON,			 CmStop),
  EV_COMMAND(CM_HORSTBUTTON,			 CmChangeVoiceHorst),
  EV_COMMAND(CM_LIOBABUTTON,			 CmChangeVoiceLioba),
END_RESPONSE_TABLE;

const unsigned TEditWindow::InputTextLen  = 51;
const unsigned TEditWindow::FirstNChars   = 20;

//
// Constructor.  Setup menu and text areas.
//
TEditWindow::TEditWindow(const char* title)
	: TFrameWindow(0, title), TWindow(0, title)
{
  const int labelStartX = 10,
				textStartY = 225,
				textHeight = 16,
				textStartX = labelStartX + 250;

  // setup menu
  //
  AssignMenu("IDM_EXAMPLE_EDIT");

  Attr.Style = Attr.Style | WS_MAXIMIZE ;

  // Create Edit control.
  //
  EditCntl = new TExampleEdit(this, ID_EXAMPLE_EDIT, "");


  PitchSlider = new TVSlider(this,-1,0,220,90,80) ;
  SpeechrateSlider = new TVSlider(this,-1,100,220,90,80) ;
  PitchRangeSlider = new TVSlider(this,-1,0,340,90,80) ;
  DeclinationSlider = new TVSlider(this,-1,100,340,90,80) ;
  SpeakButton = new TButton(this,CM_SYNBUTTON,"Speak",10,10,80,50) ;
  StopButton = new TButton(this,CM_STOPBUTTON,"Stop",110,10,80,50) ;
  VoiceBox = new TGroupBox(this,CM_VOICEBOX,"VOICE",10,70,180,100) ;
  HorstButton = new TRadioButton(this,CM_HORSTBUTTON,"Horst",20,100,160,30,VoiceBox) ;
  LiobaButton = new TRadioButton(this,CM_LIOBABUTTON,"Lioba",20,130,160,30,VoiceBox) ;
  new TStatic(this,-1," pitch",0,200,90,20,7) ;
  new TStatic(this,-1,"speechrate",100,200,90,20,11) ;
  new TStatic(this,-1," pitchrange",0,320,90,20,12) ;
  new TStatic(this,-1,"declination",100,320,90,20,11) ;

//  MyScroller = new TScroller(this,10,10,800,600) ;
//  FileNameField = new TStatic(this, -1, "noname.txt",0, 600,200, 20, 10);
/*  // setup static text areas.
  //
  new TStatic(this, -1, "Number of lines:",  labelStartX, textStartY,
				  160, textHeight, 16);

  new TStatic(this, -1, "current line number:",  labelStartX,
				  textStartY + textHeight, 200, textHeight, 20);
  CurLineNbrText = new TStatic(this, -1, "0",  textStartX,
				  textStartY + textHeight, 50, textHeight, 5);
  new TStatic(this, -1, "1st 20 chars of current line:",  labelStartX,
				  textStartY + textHeight * 2, 290, textHeight, 29);
  CurLineText = new TStatic(this, -1, "",  textStartX,
				  textStartY + textHeight * 2, FirstNChars * 10, textHeight,
				  FirstNChars);
  new TStatic(this, -1, "length of current line:",  labelStartX,
				  textStartY + textHeight * 3, 230, textHeight, 23);
  CurLineLenText = new TStatic(this, -1, "0",  textStartX,
				  textStartY + textHeight * 3, 50, textHeight, 5);
  new TStatic(this, -1, "line number of 1st visible list:",  labelStartX,
				  textStartY + textHeight * 4, 320, textHeight, 32);
  FirstVisibleLineText = new TStatic(this, -1, "0",  textStartX,
				  textStartY + textHeight * 4, 50, textHeight, 5);
  new TStatic(this, -1, "has edit control been modified:",  labelStartX,
				  textStartY + textHeight * 5, 310, textHeight, 31);
  IsModifiedText = new TStatic(this, -1, "No",  textStartX,
				  textStartY + textHeight * 5, 50, textHeight, 5);
  new TStatic(this, -1, "last clipboard operation:",  labelStartX,
				  textStartY + textHeight * 6, 250, textHeight, 25);
  LastCBOpText = new TStatic(this, -1, "",  textStartX,
				  textStartY + textHeight * 6, 100, textHeight, 10);
  new TStatic(this, -1, "1st 20 chars of last selected text:",  labelStartX,
				  textStartY + textHeight * 7, 350, textHeight, 35);
  CurSelText= new TStatic(this, -1, "",  textStartX,
				  textStartY + textHeight * 7, FirstNChars * 10, textHeight,
				  FirstNChars);
*/
  synthi = new Synthese(NULL,szProgramPath) ;
  voicepath = synthi->get_voice() ;
  char* p = strrchr(voicepath, '\\');
  *(p + 1) = '\0';
  voices[0] = "lioba" ;
  voices[1] = "horst" ;
  defaultvoice = 0 ;
  synthi->change_voice(voicepath,voices[defaultvoice]) ;

}

void
TEditWindow::CmChangeVoiceLioba() {
  defaultvoice = 0 ;
  synthi->change_voice(voicepath,voices[defaultvoice]) ;
  defaultpitch = (int)synthi->get_pitch() ;
  PitchSlider->SetPosition(defaultpitch) ;
  defaultspeechrate = (int)(synthi->get_speechrate()*10.0) ;
  SpeechrateSlider->SetPosition(defaultspeechrate) ;
  defaultpitchrange =  (int)synthi->get_pitchrange();
  PitchRangeSlider->SetPosition(defaultpitchrange) ;
  defaultdeclination = (int)synthi->get_declination() ;
  DeclinationSlider->SetPosition(defaultdeclination) ; }

void
TEditWindow::CmChangeVoiceHorst() {
  defaultvoice = 1  ;
  synthi->change_voice(voicepath,voices[defaultvoice]) ;
  defaultpitch = (int)synthi->get_pitch() ;
  PitchSlider->SetPosition(defaultpitch) ;
  defaultspeechrate = (int)(synthi->get_speechrate()*10.0) ;
  SpeechrateSlider->SetPosition(defaultspeechrate) ;
  defaultpitchrange =  (int)synthi->get_pitchrange();
  PitchRangeSlider->SetPosition(defaultpitchrange) ;
  defaultdeclination = (int)synthi->get_declination() ;
  DeclinationSlider->SetPosition(defaultdeclination) ; }





void
TEditWindow::CmNewVoice() {
  TOpenSaveDialog::TData Voice ;
  Voice.Flags = OFN_FILEMUSTEXIST|OFN_PATHMUSTEXIST;
  Voice.SetFilter("Inventory index files (*.IND)|*.IND");
  Voice.FileName = synthi->get_voice() ;
  char* p, *q , *r;
  if (TFileOpenDialog(GetApplication()->MainWindow, Voice).Execute() == IDOK) {
  p = strrchr(Voice.FileName, '\\');
  r = strdup(&p[1]) ;
  *(p + 1) = '\0';
  q = strrchr(r,'.') ;
  *(q) = '\0' ;
  synthi->change_voice(Voice.FileName,r) ;
  defaultpitch = (int)synthi->get_pitch() ;
  PitchSlider->SetPosition(defaultpitch) ;
  defaultspeechrate = (int)(synthi->get_speechrate()*10.0) ;
  SpeechrateSlider->SetPosition(defaultspeechrate) ;
  defaultpitchrange =  (int)synthi->get_pitchrange();
  PitchRangeSlider->SetPosition(defaultpitchrange) ;
  defaultdeclination = (int)synthi->get_declination() ;
  DeclinationSlider->SetPosition(defaultdeclination) ;
  delete(r) ; }
}

void
TEditWindow::CmNewSpeechRate() {
  char buf[10] = "";
  char prompt[60] ;
  sprintf(prompt,"Old Speech Rate: %5.3f - Enter new value:",synthi->get_speechrate()) ;
  int  ok = TInputDialog(this, "New Speech Rate", prompt, buf, sizeof(buf), 0, NULL).Execute() == IDOK;
  if (ok) {
	synthi->change_speechrate(atof(buf)) ;
	SpeechrateSlider->SetPosition(int(atof(buf)*10.0)) ; }
}

void
TEditWindow::CmNewPitch() {
  char buf[10] = "";
  char prompt[60] ;
  sprintf(prompt,"Old Pitch: %5.3f - Enter new value:",synthi->get_pitch()) ;
  int  ok = TInputDialog(this, "New Pitch", prompt, buf, sizeof(buf), 0, NULL).Execute() == IDOK;

  if (ok) {
	synthi->change_pitch(atof(buf)) ;
	PitchSlider->SetPosition(atoi(buf)) ; }
}


void
TEditWindow::CmDefault() {
	PitchSlider->SetPosition(defaultpitch) ;
	SpeechrateSlider->SetPosition(defaultspeechrate) ;
	PitchRangeSlider->SetPosition(defaultpitchrange) ;
	DeclinationSlider->SetPosition(defaultdeclination) ; }

void
TEditWindow::CmShowValues() {
	char databuffer[200] ;
	sprintf(databuffer,"Pitch: %d\nPitch Range: %d\nDeclination: %d\nSpeech Rate: %5.3f\n",
		PitchSlider->GetPosition(),PitchRangeSlider->GetPosition(),DeclinationSlider->GetPosition(),
		(float)SpeechrateSlider->GetPosition()/10.0) ;
	MessageBox(databuffer,"Parameter Values",MB_OK) ;
	; }

void
TEditWindow::CmStop() {
   synthi->finish = 1 ; }

/*
void
TEditWindow::Close() {
	delete(synthi) ;
   delete(voicepath) ;
	synthi = NULL ; }
*/

void
TEditWindow::give_changes() {
	float result ;
	result = (float)SpeechrateSlider->GetPosition() / 10.0 ;
	synthi->change_speechrate(result) ;
	result = (float)PitchSlider->GetPosition() ;
	synthi->change_pitch(result) ;
	result = (float)PitchRangeSlider->GetPosition() ;
	synthi->change_pitchrange(result) ;
	result = (float)DeclinationSlider->GetPosition() ;
	synthi->change_declination(result) ; }

void
TEditWindow::CmSynthesize() {
	float result ;
	result = (float)SpeechrateSlider->GetPosition() / 10.0 ;
	synthi->change_speechrate(result) ;
	result = (float)PitchSlider->GetPosition() ;
	synthi->change_pitch(result) ;
	result = (float)PitchRangeSlider->GetPosition() ;
	synthi->change_pitchrange(result) ;
	result = (float)DeclinationSlider->GetPosition() ;
   char fnamtmp[L_tmpnam] ;
   tmpnam(fnamtmp) ;
	EditCntl->SaveTextNoQuery(fnamtmp) ;
	synthi->change_declination(result) ;
	::SetCursor(::LoadCursor(NULL,IDC_WAIT)) ;
	char* select = EditCntl->Selection() ;
	if (select != NULL) {
		EditCntl->SaveSelection(fnamtmp,select) ;
		delete(select) ;
		synthi->talk(NULL,0,fnamtmp,0,(fprt)dummy) ; }
	else
		synthi->talk(NULL,0,fnamtmp,0,(fprt)dummy) ;
   unlink(fnamtmp) ;
	::SetCursor(::LoadCursor(NULL,IDC_ARROW)) ; }

void
TEditWindow::CmSynthFileAsWav() {
	TOpenSaveDialog::TData  FileData;      // save/restore info.
	FileData.Flags = OFN_FILEMUSTEXIST|OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT;
	FileData.SetFilter("Text files (*.TXT)|*.TXT|AllFiles (*.*)|*.*|");
	float result ;
	result = (float)SpeechrateSlider->GetPosition() / 10.0 ;
	synthi->change_speechrate(result) ;
	result = (float)PitchSlider->GetPosition() ;
	synthi->change_pitch(result) ;
	result = (float)PitchRangeSlider->GetPosition() ;
	synthi->change_pitchrange(result) ;
	result = (float)DeclinationSlider->GetPosition() ;
	synthi->change_declination(result) ;
	::SetCursor(::LoadCursor(NULL,IDC_WAIT)) ;
   char inputfile[256] ;
	if (TFileOpenDialog(this, FileData).Execute() == IDOK) {
   	strcpy(inputfile,(char*)FileData.FileName) ;
	   char* resfn = NULL ;
      strcpy(FileData.FileName,"") ;
		FileData.Flags = OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT;
		FileData.SetFilter("Wave files (*.WAV)|*.WAV|AllFiles (*.*)|*.*|");
		if (TFileSaveDialog(this, FileData).Execute() == IDOK)
   		resfn = FileData.FileName ;
      TDialog* td = new TDialog(this,IDD_DIALOG1) ;
      td->Create() ;
	   synthi->talk(resfn,0,inputfile,0,(fprt)dummy) ;
		td->Destroy() ;
      delete(td) ; }
	::SetCursor(::LoadCursor(NULL,IDC_ARROW)) ; }

void
TEditWindow::CmSynthesizeFile() {
	TOpenSaveDialog::TData  FileData;      // save/restore info.
	float result ;
	result = (float)SpeechrateSlider->GetPosition() / 10.0 ;
	synthi->change_speechrate(result) ;
	result = (float)PitchSlider->GetPosition() ;
	synthi->change_pitch(result) ;
	result = (float)PitchRangeSlider->GetPosition() ;
	synthi->change_pitchrange(result) ;
	result = (float)DeclinationSlider->GetPosition() ;
	synthi->change_declination(result) ;
	::SetCursor(::LoadCursor(NULL,IDC_WAIT)) ;
   char inputfile[256] ;
	FileData.Flags = OFN_FILEMUSTEXIST|OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT;
	FileData.SetFilter("Text files (*.TXT)|*.TXT|AllFiles (*.*)|*.*|");
	if (TFileOpenDialog(this, FileData).Execute() == IDOK) {
   	strcpy(inputfile,(char*)FileData.FileName) ;
	   synthi->talk(NULL,0,inputfile,0,(fprt)dummy) ; }
	::SetCursor(::LoadCursor(NULL,IDC_ARROW)) ; }

void
TEditWindow::CmSynthAsWav() {
	TOpenSaveDialog::TData  FileData;      // save/restore info.
	float result ;
	result = (float)SpeechrateSlider->GetPosition() / 10.0 ;
	synthi->change_speechrate(result) ;
	result = (float)PitchSlider->GetPosition() ;
	synthi->change_pitch(result) ;
	result = (float)PitchRangeSlider->GetPosition() ;
	synthi->change_pitchrange(result) ;
	result = (float)DeclinationSlider->GetPosition() ;
	synthi->change_declination(result) ;
	::SetCursor(::LoadCursor(NULL,IDC_WAIT)) ;
   char fnamtmp[L_tmpnam] ;
   tmpnam(fnamtmp) ;
	EditCntl->SaveTextNoQuery(fnamtmp) ;
	synthi->change_declination(result) ;
	::SetCursor(::LoadCursor(NULL,IDC_WAIT)) ;
   char* resfn = NULL ;
	FileData.Flags = OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT;
	FileData.SetFilter("Wave files (*.WAV)|*.WAV|AllFiles (*.*)|*.*|");
	if (TFileSaveDialog(this, FileData).Execute() == IDOK)
   	resfn = FileData.FileName ;
   TDialog* td = new TDialog(this,IDD_DIALOG1) ;
   td->Create() ;
	char* select = EditCntl->Selection() ;
	if (select != NULL) {
		EditCntl->SaveSelection(fnamtmp,select) ;
		delete(select) ;
		synthi->talk(resfn,0,fnamtmp,0,(fprt)dummy) ; }
	else
		synthi->talk(resfn,0,fnamtmp,0,(fprt)dummy) ;
   unlink(fnamtmp) ;
	td->Destroy() ;
   delete(td) ;
	::SetCursor(::LoadCursor(NULL,IDC_ARROW)) ; }

/*
void
TEditWindow::CmSynthesizeWithYourPitch() {
	float result ;
	result = (float)SpeechrateSlider->GetPosition() / 10.0 ;
	synthi->change_speechrate(result) ;
	result = (float)PitchSlider->GetPosition() ;
	synthi->change_pitch(result) ;
	result = (float)PitchRangeSlider->GetPosition() ;
	synthi->change_pitchrange(result) ;
	result = (float)AccentlengthSlider->GetPosition() / 10.0 ;
	synthi->change_accentlength(result) ;
	result = (float)FinallengthSlider->GetPosition() / 10.0 ;
	synthi->change_finallengthening(result) ;
	result = (float)DeclinationSlider->GetPosition() ;
	EditCntl->SaveTextNoQuery() ;
	synthi->change_declination(result) ;
	::SetCursor(::LoadCursor(NULL,IDC_WAIT)) ;

	char* select = EditCntl->Selection() ;
	if (select != NULL) {
		EditCntl->SaveSelection("hadi.tmp",select) ;
		delete(select) ;
		synthi->talk(NULL,1,"hadi.tmp",0,(fprt)dummy) ; }
	else
		synthi->talk(NULL,1,EditCntl->GetFileName(),0,(fprt)dummy) ;
	::SetCursor(::LoadCursor(NULL,IDC_ARROW)) ; }

void
TEditWindow::CmSynthesizeWithYourProsody() {
	float result ;
	result = (float)SpeechrateSlider->GetPosition() / 10.0 ;
	synthi->change_speechrate(result) ;
	result = (float)PitchSlider->GetPosition() ;
	synthi->change_pitch(result) ;
	result = (float)PitchRangeSlider->GetPosition() ;
	synthi->change_pitchrange(result) ;
	result = (float)AccentlengthSlider->GetPosition() / 10.0 ;
	synthi->change_accentlength(result) ;
	result = (float)FinallengthSlider->GetPosition() / 10.0 ;
	synthi->change_finallengthening(result) ;
	result = (float)DeclinationSlider->GetPosition() ;
	EditCntl->SaveTextNoQuery() ;
	synthi->change_declination(result) ;
	::SetCursor(::LoadCursor(NULL,IDC_WAIT)) ;
	synthi->talk(NULL,2,EditCntl->GetFileName(),0,(fprt)dummy) ;
	::SetCursor(::LoadCursor(NULL,IDC_ARROW)) ; }

void
TEditWindow::CmSymbolicsOnly() {
	float result ;
	result = (float)SpeechrateSlider->GetPosition() / 10.0 ;
	synthi->change_speechrate(result) ;
	result = (float)PitchSlider->GetPosition() ;
	synthi->change_pitch(result) ;
	result = (float)PitchRangeSlider->GetPosition() ;
	synthi->change_pitchrange(result) ;
	result = (float)AccentlengthSlider->GetPosition() / 10.0 ;
	synthi->change_accentlength(result) ;
	result = (float)FinallengthSlider->GetPosition() / 10.0 ;
	synthi->change_finallengthening(result) ;
	result = (float)DeclinationSlider->GetPosition() ;
	EditCntl->SaveTextNoQuery() ;
	synthi->change_declination(result) ;
	::SetCursor(::LoadCursor(NULL,IDC_WAIT)) ;
	synthi->talk(NULL,3,EditCntl->GetFileName(),0,(fprt)dummy) ;
	::SetCursor(::LoadCursor(NULL,IDC_ARROW)) ; }

void
TEditWindow::CmOnwardFromSymbolics() {
	float result ;
	result = (float)SpeechrateSlider->GetPosition() / 10.0 ;
	synthi->change_speechrate(result) ;
	result = (float)PitchSlider->GetPosition() ;
	synthi->change_pitch(result) ;
	result = (float)PitchRangeSlider->GetPosition() ;
	synthi->change_pitchrange(result) ;
	result = (float)AccentlengthSlider->GetPosition() / 10.0 ;
	synthi->change_accentlength(result) ;
	result = (float)FinallengthSlider->GetPosition() / 10.0 ;
	synthi->change_finallengthening(result) ;
	result = (float)DeclinationSlider->GetPosition() ;
	EditCntl->SaveTextNoQuery() ;
	synthi->change_declination(result) ;
	::SetCursor(::LoadCursor(NULL,IDC_WAIT)) ;
	synthi->talk(NULL,4,EditCntl->GetFileName(),0,(fprt)dummy) ;
	::SetCursor(::LoadCursor(NULL,IDC_ARROW)) ; }

void
TEditWindow::CmPreprocess() {
	EditCntl->SaveTextNoQuery() ;
	::SetCursor(::LoadCursor(NULL,IDC_WAIT)) ;
	synthi->preprocess("hadi.vv",EditCntl->GetFileName()) ;
	::SetCursor(::LoadCursor(NULL,IDC_ARROW)) ; }
*/

bool
TEditWindow::CanClose()
{
  delete (synthi) ;
  synthi = NULL ;
  delete (voicepath) ;
  return true ; }

void
TEditWindow::SetupWindow()
{
  TFrameWindow::SetupWindow();
  PitchSlider->SetRange(50,400) ;
  PitchSlider->SetRuler(0,false) ;
  defaultpitch = (int)synthi->get_pitch() ;
  PitchSlider->SetPosition(defaultpitch) ;
  SpeechrateSlider->SetRange(5,25) ;
  SpeechrateSlider->SetRuler(0,false) ;
  defaultspeechrate = (int)(synthi->get_speechrate()*10.0) ;
  SpeechrateSlider->SetPosition(defaultspeechrate) ;
  PitchRangeSlider->SetRange(0,300) ;
  PitchRangeSlider->SetRuler(0,false) ;
  defaultpitchrange =  (int)synthi->get_pitchrange();
  PitchRangeSlider->SetPosition(defaultpitchrange) ;
  DeclinationSlider->SetRange(-100,200) ;
  DeclinationSlider->SetRuler(0,false) ;
  defaultdeclination = (int)synthi->get_declination() ;
  DeclinationSlider->SetPosition(defaultdeclination) ;
  UpdateTextFields();
  LiobaButton->Check() ;
  HorstButton->Uncheck() ;
  Attr.Style = Attr.Style | WS_MAXIMIZE ;

//  SetScroller(MyScroller) ;
//  MyScroller->SetPageSize() ;

}

void TEditWindow::CmAbout() {
	char databuffer[200] ;
	sprintf(databuffer,"Hadifix 32 bit Demo Version 0.89\n\n17.5.1999\nThomas Portele\nInstitut für Kommunikationsforschung und Phonetik\nUniversität Bonn\n") ;
	MessageBox(databuffer,"HADIFIX DEMO",MB_OK) ; }

void TEditWindow::CmHelp() {
	WinHelp("hadifix.hlp", HELP_INDEX, NULL); }


//
// CmInsertText(). Insert text at character position input be user. If pos
// is beyond end of edit buffer then the insert takes place at the end of
// buffer (append).
//
void
TEditWindow::CmInsertText()
{
  char     buf[InputTextLen] = "";
  unsigned pos;

  if (!InputNumber("Enter position:", pos))
	 return;
  EditCntl->SetSelection(pos, pos);

  buf[0] = 0;
  if (!InputString("Enter string:", buf))
	 return;
  EditCntl->Insert(buf);
  UpdateTextFields();
}

//
// CmDeleteSubText().  Delete characters between start position and end
// position (input by user).
//
void
TEditWindow::CmDeleteSubText()
{
  unsigned sPos, ePos;

  if (!InputNumber("Enter starting position", sPos))
	 return;

  if (!InputNumber("Enter ending position", ePos))
	 return;

  EditCntl->DeleteSubText(sPos, ePos);
  UpdateTextFields();
}

//
// CmDeleteLine().  Delete line of text.  Line number input by user.
//
void
TEditWindow::CmDeleteLine()
{
  unsigned line;

  if (!InputNumber("Enter line number:", line))
	 return;
  EditCntl->DeleteLine(line);
  UpdateTextFields();
}

//
// SaveText().  Save text of edit control to a file.
//

void TEditWindow::CmNewText()
{
	EditCntl->SaveText() ;
	EditCntl->ChangeName("noname.txt") ;
	EditCntl->CmEditClear() ;
}

void TEditWindow::CmSaveText()
{
  EditCntl->SaveText();
//  FileNameField->SetText(EditCntl->GetFileName()) ;
}

//
// RestoreText().  retore text of edit control from a file.
//
void TEditWindow::CmRestoreText()
{
  EditCntl->RestoreText();
  UpdateTextFields();
}

//
// UpdateTextFields(). Updates text fields that reflex the edit control's state.
//
void
TEditWindow::UpdateTextFields()
{
/*  char        buf[FirstNChars+1] = "";
  UINT        sPos, ePos, curLine;

  // get the line that the caret is currently on.
  //
  EditCntl->GetSelection(sPos, ePos);
  curLine = EditCntl->GetLineFromPos(ePos);

  itoa(curLine, buf, 10);
  CurLineNbrText->SetText(buf);

  itoa(EditCntl->GetNumLines(), buf, 10);
  NbrLinesText->SetText(buf);

  EditCntl->GetLine(buf, FirstNChars, curLine);
  CurLineText->SetText(buf);

  itoa(EditCntl->GetLineLength(curLine), buf, 10);
  CurLineLenText->SetText(buf);

  itoa(EditCntl->GetFirstVisibleLine(), buf, 10);
  FirstVisibleLineText->SetText(buf);

  if (EditCntl->IsModified())
	 IsModifiedText->SetText("Yes");
  else
	 IsModifiedText->SetText("No");

  LastCBOpText->SetText(EditCntl->LastCBOpStr.c_str());

  EditCntl->GetSubText(buf, sPos, min(ePos, (unsigned)FirstNChars));
  if (buf[0])
	 CurSelText->SetText(buf); */ ;
}

//
// ResetTextFields(). Reset text fields to blanks.
//
void
TEditWindow::ResetTextFields()
{
/*  NbrLinesText->SetText("0");
  CurLineNbrText->SetText("0");
  CurLineText->SetText("");
  CurLineLenText->SetText("0");
  FirstVisibleLineText->SetText("0");
  IsModifiedText->SetText("No");
  LastCBOpText->SetText("");
  CurSelText->SetText("") */ ;
}

//
// InputString(). Get string from user.  Return 1 if successful, 0 otherwise.
// assumes buffer size of InputTextLen.
//
int
TEditWindow::InputString(char* prompt, char* s)
{
  return TInputDialog(this, "String", prompt, s, InputTextLen).Execute() == IDOK;
}

//
// InputNumber(). Get number from user.  Return 1 if successful, 0 otherwise.
//
int
TEditWindow::InputNumber(char* prompt, unsigned& n)
{
  char buf[10] = "";
  int  ok = TInputDialog(this, "Number", prompt, buf, sizeof(buf), 0,
								 new TFilterValidator("0-9")).Execute() == IDOK;
  if (ok)
	 n = atoi(buf);
  return ok;
}

//----------------------------------------------------------------------------

class TExampleEditApp : public TApplication {
  public:
	 void  InitMainWindow();
//	 void Close() ;
};


void
TExampleEditApp::InitMainWindow()
{
  int i;
  char *p;
  h = NULL;
  i = GetModuleFileName(szProgramPath, sizeof(szProgramPath));
  p = strrchr(szProgramPath, '\\');
  *(p + 1) = '\0';
  strcat(szProgramPath,"data\\") ;
  MainWindow = new TEditWindow("HADIFIX Demo");
}

/*
void
TExampleEditApp::Close() {
	((TEditWindow*)(MainWindow))->Close()
	; }
*/

TExampleEditApp* app ;

int dummy() {
	((TEditWindow*)(app->MainWindow))->give_changes() ;
	return(app->PumpWaitingMessages()) ;
}

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  app = new TExampleEditApp() ;
  app->Run() ;
//  app->Close() ;
}
