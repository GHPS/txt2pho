#include "debug.h"
#include "ipa.h"
#include "lexicon.h"




extern int language ;


////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////                                                                                ////
////  class TLexicon                                                                ////
////                                                                                ////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////
//
//  TLexicon::TLexicon (...)
//
//  Eingabe:
//      const string &datapath
//          Name des Verzeichnisses, in dem die Dateien fNr das Lexikon liegen
//  Zweck:
//      Baut ein Lexikon auf. Dazu werden die Tabelle der Wörter und Transkriptionen,
//      die Liste der Funktionswörter, drei verschiedene Regelapparate fNr die
//      Wortflexion und ein Regelapparat fNr die Fugenmorpheme von Komposita geladen und
//      eine Instanz von P-TRA erzeugt.
//  Seiteneffekte:
//      keine:
//  Ausgabe:
//      keine:

TLexicon::TLexicon (const string &datapath):
	table(datapath, "hadifix"),
	brittable(datapath,"hadibrit") ,
	flexion(datapath, "hadifix")
{

#if !defined(NPETRA)
	ptra = new PTRA(datapath, "hadifix");
#endif

	statistics("Lexicon initialized") ;

}


////////////////////////////////////////////////////////////////////////////////////////
//
//  TLexicon::~TLexicon (...)
//
//  Eingabe:
//      keine
//  Zweck:
//      Entfernt das Lexikon. Die P-TRA-Instanz, die vom Konstruktor angelegt wurde,
//      wird explizit gelöscht.
//  Seiteneffekte:
//      keine
//  Ausgabe:
//      keine

TLexicon::~TLexicon ()
{
#if !defined(NPETRA)
	delete ptra;
#endif
}


////////////////////////////////////////////////////////////////////////////////////////

void TLexicon::transcribe (TLexem &lexem, int sevenbit)
{	statistics("transcribe (TLexem &lexem = \"" << lexem.Chars() << "\")");

	char* tempstr ;
	char* t2str ;

	bool transcribed = false;
#if !defined(NPETRA)
	bool transcribed_by_PTRA = false;
#endif

	email = sevenbit ;

   statistics("email in transcribe " << email) ;


	if (lexem.Type() == TLexem::control) {
		transcribed = transcribed_by_PTRA = transcribe_with_PTRA(lexem);
		t2str = strdup(lexem.Transcription().c_str()) ;
		tempstr = ptra->accents(ptra->sylborders(t2str, transcribed_by_PTRA));
		lexem.transcription = tempstr;
		CLEAR(tempstr);
                return ; }


	if (lexem.Type() != TLexem::wordform)
		return;

#if !defined(NLEXICON)

	transcribed = transcribe_literally(lexem);
	if (!transcribed)
	{
		transcribed = transcribe_as_inflected(lexem);
		if (!transcribed)
		{
			TLexemNode* decomposition = new TLexemNode(TLexem(""), lexem);
			transcribed = transcribe_as_compound(decomposition);
			if (transcribed)
			{
				int score;
            int penalty ;

				if (decomposition->is_unwanted())
					transcribed = false;
				else
					lexem = get_best_decomposition(decomposition, score, penalty);
			}
			delete(decomposition) ;
		}
	}

#endif

#if !defined(NSPELLING)
	if (!transcribed && (lexem.contains_only(asc_upper_chars) || lexem.contains_only(asc_consonants)))
		transcribed = transcribe_as_abbreviation(lexem);
#endif

#if !defined(NPETRA)
	if (!transcribed)
	{
		transcribed = transcribed_by_PTRA = transcribe_with_PTRA(lexem);
	}
#endif
	if (!transcribed) {
   	lexem.type = TLexem::nothing ;
      return ; }

  statistics("Akzente und Silbengrenzen!");
#if !defined(NPETRA)
	t2str = strdup(lexem.Transcription().c_str()) ;
	tempstr = ptra->accents(ptra->sylborders(t2str, transcribed_by_PTRA));
	lexem.transcription = tempstr;
	CLEAR(tempstr);
#endif

  statistics("Transkription erfolgreich!") ;
//  cout << lexem.Transcription() << " ";
}


////////////////////////////////////////////////////////////////////////////////////////
//
//  TLexicon::transcribe_literally (...)
//
//  Eingabe:
//      TLexem &lexem
//          das Lexem, das transkribiert werden soll
//      TWordClass wcl
//          Die Wortart, der das Lexem angehören soll. Sie ist aus »Unknowna, wenn keine
//          Anforderungen gestellt werden.
//  Zweck:
//      Versucht ein Lexem mit Hilfe des Lexikons zu transkribieren.
//  Seiteneffekte:
//      In »lexema wird im Erfolgsfall die Transkription zurNckgegeben
//  Ausgabe:
//      keine


bool TLexicon::transcribe_literally (TLexem &lexem, TWordClass wcl)
{	statistics("literally (TLexem &lexem = \"" << lexem.Chars() << "\", TWordClass wcl = " << wcl2str(wcl) << ")");

	valid_prefix = 1 ;




   if (language == 0 && (strlen(lexem.Chars().c_str()) > 1 || wcl != Unknown))
		if (!lexem.is_valid_word()) {
			statistics("Invalid Word") ;
			return false; }




	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Suche das Lexem im Lexikon. Dabei wird die Groß-/Kleinschreibung beachtet. Wird
	// kein Eintrag im Lexikon gefunden, dann findet eine erneute Suche ohne Beachtung
	// der Groß-/Kleinschreibung statt.


	long i ;



   if (language == 1)
	   i= brittable.Search(lexem.Chars(), true);
   else
	   i= table.Search(lexem.Chars(), true);


	if (i == -1 || i == -2)
   	if (language == 1)
      	i = brittable.Search(lexem.Chars(), false) ;
      else
			i = table.Search(lexem.Chars(), false);



	TLexem xtmp = lexem ;
	if (i==-1 || i == -2) {
	  if (xtmp.EmailChange() == 1) {
	    i = table.Search(xtmp.Chars(),true) ;
	    if (i==-1 || i == -2)
	      i = table.Search(xtmp.Chars(),false) ; } }
       
       
	



	// Wurde ein Lemma gefunden?
	if (i != -1 && i != -2)
	{
#ifndef NEWTABLE
		TTable::TRecord record = table[i];
#else
		Newtable::TRecord record ;
      if (language == 1)
      	record = brittable[i] ;
      else
      	record = table[i] ;
#endif
      fprintf(stderr,"LEMMA %ld\n",i) ;
      fflush(stderr) ;
		statistics("Lemma fetched") ;

		// Wird keine bestimmte Wortart verlangt, soll ein Teil eines Kompositums
		// transkribiert werden oder hat das Lemma die verlangte Wortart?
		if (wcl == Unknown || wcl == KMP || record.has_word_class(wcl))
		{
			size_t pos = record.Transcription().find(ipa_primary_stress);

#ifdef Windows
			if (pos == NPOS)
#else
			if (pos == string::npos)
#endif
				lexem.transcription = ipa_primary_stress + record.Transcription();
			else
				lexem.transcription = record.Transcription();
			lexem.lemma = record.Lemma();

			if (wcl == Unknown || wcl == KMP)
				lexem.SetWordClasses(record.WordClassesCount(), record.WordClasses());
			else
				lexem.SetWordClass(wcl);
			statistics ("Result in literally " << true << " WCL " << lexem.wordClasses[0]) ;
			statistics (record.Transcription() << record.Lemma() ) ;
			return true;
		}
		else {
			statistics ("Result in literally " << false) ;
			return false; }
	}
	else {
		statistics ("Result in literally " << false) ;
//		if (i == -2)
//			valid_prefix = 0 ;
		return false; }
}


////////////////////////////////////////////////////////////////////////////////////////

#if !defined(NSPELLING)

bool TLexicon::transcribe_as_abbreviation (TLexem &lexem)
{	statistics("abbreviation (TLexem &lexem = \"" << lexem.Chars() << "\")");

	string s;
	char c;

	for (int i = 0; i < (int)lexem.Chars().length() - 1; i++)
	{
		c = toupper(lexem.Chars(i));
		if (c == asc_A_umlaut || c == asc_a_umlaut)
			c = 26;
		else if (c == asc_O_umlaut || c == asc_o_umlaut)
			c = 27;
		else if (c == asc_U_umlaut || c == asc_u_umlaut)
			c = 28;
		else if (c == asc_sz_lig)
		{
			s += spelling['S' - 'A'];
			c = 'Z' - 'A';
		}
		else
			c -= 'A';
		s += spelling[c];
	}
	c = toupper(lexem.Chars(lexem.Chars().length() - 1));
	if (c == asc_A_umlaut || c == asc_a_umlaut)
		c = 26;
	else if (c == asc_O_umlaut || c == asc_o_umlaut)
		c = 27;
	else if (c == asc_U_umlaut || c == asc_u_umlaut)
		c = 28;
	else if (c == asc_sz_lig)
	{
		s += spelling['S' - 'A'];
		c = 'Z' - 'A';
	}
	else
		c -= 'A';
	s += "'";
	s += spelling[c];
	lexem.lemma = "AbkNrzung";
	lexem.transcription = s;
	lexem.SetWordClass(NAM);
	return true;
}

#endif


////////////////////////////////////////////////////////////////////////////////////////

bool TLexicon::transcribe_as_inflected (TLexem &lexem, TWordClass wcl)
{	statistics("inflected (TLexem &lexem = \"" << lexem.Chars() << "\", TWordClass wcl = " << wcl2str(wcl) << ")");

	statistics("email " << email) ;

	// Eine flektierte Form eines deutschen Wortes hat mindestens drei Buchstaben.
	if (lexem.Chars().length() < 3)
		return false;

	if (!lexem.is_valid_word())
		return false;

	bool transcribed = false;
	char ch = lexem.Chars(lexem.Chars().length() - 1);
	TLexem tmp = lexem ;

	TLexem xtmp = lexem ;
	if (xtmp.SetUmlaut(0) == 1)
		transcribed = transcribe_literally(xtmp, Unknown);

	
	if (!transcribed && email) {
	  xtmp = lexem ;
	  if (xtmp.EmailChange() == 1) {
	    transcribed = transcribe_literally(xtmp, Unknown);
	    if (!transcribed)
	      if (xtmp.SetUmlaut(0) == 1)
		transcribed = transcribe_literally(xtmp, Unknown); } }
		
	statistics(transcribed << " " << xtmp.Transcription() << " " << xtmp.Chars()) ;


	if (transcribed)
				{
				  xtmp.chars = lexem.Chars() ;
				  xtmp.SetUmlautPhon() ;
				  lexem = xtmp ;
				}


   if (!transcribed) {
	for (short i = 0; i < flexion.Entries(ch); i++)
	{
		TFlexion::TRule rule = flexion(ch, i);

		

		if ((rule.promote_from == wcl || (wcl == Unknown && rule.promote_from != KMP)) && lexem.has_ending(rule))
		{

			tmp = lexem;
			tmp.flexrul = rule.orth_flex + " " + rule.orth_base + " " + rule.phon_base + " " + rule.phon_flex ;
			size_t flex_pos = tmp.Chars().length() - rule.orth_flex.length();

			tmp.SetChars(flex_pos, rule.orth_base);
			transcribed = transcribe_literally(tmp, rule.promote_from);

			statistics("WCL " << tmp.wordClasses[0] << " RULE " << rule.promote_from) ;

			if (transcribed && rule.promote_from == KMP) {
				if (tmp.wordClasses[0] == ADD || tmp.wordClasses[0] == ART ||
				    tmp.wordClasses[0] == PPR || tmp.wordClasses[0] == INJ ||
				    tmp.wordClasses[0] == PRO || tmp.wordClasses[0] == QAV) {
					statistics("Inflection invalid") ;
					transcribed = false ; } }


			if (transcribed)
			{
				tmp.chars = lexem.Chars();

				flex_pos = tmp.Transcription().length() - rule.phon_base.length();
				if (tmp.Transcription(flex_pos, tmp.Transcription().length() - flex_pos) == rule.phon_base)
				{
					tmp.SetTranscription(flex_pos, rule.phon_flex);
					tmp.SetWordClass(rule.promote_to) ;
					break;
				}
				statistics(tmp.Transcription() << " " << rule.phon_base << " " << flex_pos) ;
			}
			if (1 /*rule.may_umlaut == true*/) {


// Hier muesste noch der Umlautungskram kommen
// Warum sind manche Regeln nicht fuer Umlautung gedacht???

				if(tmp.SetUmlaut(email) == 1)
					transcribed = transcribe_literally(tmp, rule.promote_from);

				if (transcribed && rule.promote_from == KMP) {
					if (tmp.wordClasses[0] == ADD || tmp.wordClasses[0] == ART ||
					    tmp.wordClasses[0] == PPR || tmp.wordClasses[0] == INJ ||
					    tmp.wordClasses[0] == PRO || tmp.wordClasses[0] == QAV) {
						statistics("Inflection invalid") ;
						transcribed = false ; } }

				if (transcribed)
				{

					tmp.chars = lexem.Chars();

					flex_pos = tmp.Transcription().length() - rule.phon_base.length();
					if (tmp.Transcription(flex_pos, tmp.Transcription().length() - flex_pos) == rule.phon_base)
					{
						tmp.SetTranscription(flex_pos, rule.phon_flex);
						tmp.SetWordClass(rule.promote_to) ;
						tmp.SetUmlautPhon() ;
						break;
					} } }

// Hier muesste noch der Umlautungskram kommen


		transcribed = false;
		}
	}

		if (transcribed)
			lexem = tmp; }

	statistics ("Result in as_inflected " << transcribed << " WCL " << lexem.wordClasses[0]) ;
	return transcribed;
}

bool TLexicon::transcribe_as_prefix(TLexem& lexem) {
	bool result = false ;
	if (lexem.Chars() == "be") {
   	result = true ;
      lexem.transcription = "b@" ; }
	if (lexem.Chars() == "er") {
	result = true ;
      lexem.transcription = "?E6" ; }
	if (lexem.Chars() == "de") {
	result = true ;
      lexem.transcription = "d@" ; }
	if (lexem.Chars() == "ge") {
	result = true ;
      lexem.transcription = "g@" ; }
	if (lexem.Chars() == "ent") {
	result = true ;
      lexem.transcription = "?Ent" ; }
	if (lexem.Chars() == "ver") {
	result = true ;
      lexem.transcription = "fE6" ; }
	if (lexem.Chars() == "zer") {
   	result = true ;
      lexem.transcription = "tsE6" ; }
	if (lexem.Chars() == "Be") {
   	result = true ;
      lexem.transcription = "b@" ; }
	if (lexem.Chars() == "Er") {
	result = true ;
      lexem.transcription = "?E6" ; }
	if (lexem.Chars() == "De") {
	result = true ;
      lexem.transcription = "d@" ; }
	if (lexem.Chars() == "Ge") {
	result = true ;
      lexem.transcription = "g@" ; }
	if (lexem.Chars() == "Ent") {
	result = true ;
      lexem.transcription = "?Ent" ; }
	if (lexem.Chars() == "Ver") {
	result = true ;
      lexem.transcription = "fE6" ; }
	if (lexem.Chars() == "Zer") {
   	result = true ;
      lexem.transcription = "tsE6" ; }
	if (result) {
		lexem.lemma = "Praefix";
		lexem.SetWordClass(ART); }
	return result ; }


////////////////////////////////////////////////////////////////////////////////////////

bool TLexicon::transcribe_as_compound (TLexemNode* root)
{	statistics("compound (TLexemNode *root = {\"" << root->Head().Chars() << "\", \"" << root->Rest().Chars() <<"\"})");

	// Der zu transkribierende Rest des Kompositums darf nicht die L?nge Null haben.
	assert(root->Rest().Chars().length() != 0);

	TLexem head = root->Head(), rest = root->Rest();

	// Wörter mit der L?nge Eins können nicht Teil eines Kompositums sein.
	if (rest.Chars().length() == 1)
		return false;

	// Der Rest des Kompositums muß eine gNltige Struktur besitzen.
	if (!rest.is_valid_word())
		return false;

	TLexem tmp;

	// Wurde der vordere Teil des Kompositums schon transkribiert?
	if (head.Chars().length() != 0 /*&& rest.Chars() != "er"*/)
	{
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// Versuche, den Rest des Kompositums als Ganzes zu transkribieren.

		tmp = rest;

		bool transcribed = transcribe_literally(tmp);

		if (!transcribed)
			transcribed = transcribe_as_inflected(tmp);
		if (transcribed)
		{
			root->SetRest(tmp);
			return true;
		}
	}

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// Betrachte den Rest des Kompositums wieder als Kompositum, d.h. versuche alle
	// möglichen Anf?nge des Rests zu transkribieren.

	tmp.SetChars(0, rest.Chars(0));

   size_t i ;

	// verl?ngere das tempor?re Lexem zeichenweise
	for (i = 1; i < rest.Chars().length() - 1; i++)
	{
		bool transcribed = false ;
		char ch = rest.Chars(i);
		tmp.SetChars(i, ch);

      if (strlen(tmp.Chars().c_str()) < 2)
      	continue ;

		// transkribiere das tempor?re Lexem ohne Fugenmorphem
		if (tmp.Chars() != "er" && tmp.Chars() != "Er")
			transcribed = transcribe_literally(tmp);

		if (valid_prefix == 0) {
			statistics("No valid prefix " << tmp.Chars() ) ;
			break ; }

		// wenn das nicht geklappt hat, versuch es mit Fugenmorphemen
		if (!transcribed)
			transcribed = transcribe_as_inflected(tmp, KMP);

		if (!transcribed)
			transcribed = transcribe_as_prefix(tmp) ;


#ifdef Windows
		if (transcribed)
			root->Add(new TLexemNode(tmp, rest.Chars(i + 1, rest.Chars().length() - i - 1)));
#else
		if (transcribed)
			root->insert(new TLexemNode(tmp, rest.Chars(i+1, rest.Chars().length() -i -1))) ;
#endif

		// Sind noch mindestens 3 Zeichen an das tempor?re Lexem anzuh?ngen?
		if ((!transcribed) && rest.Chars().length() - i > 3)
		{
			// Endet das tempor?re Lexem mit einem Konsonanten, und steht an der n?chsten zu
			// kopierenden Stelle der gleiche Konsonant gefolgt von einem Vokal?
			if (is_ascii_consonant(ch) && rest.Chars(i + 1) == ch && is_ascii_vowel(rest.Chars(i + 2)))
			{
				tmp.SetChars(i + 1, ch);
				transcribed = transcribe_literally(tmp);
#ifdef Windows
				if (transcribed)
					root->Add(new TLexemNode(tmp, rest.Chars(i + 1, rest.Chars().length() - i - 1)));
#else
				if (transcribed)
					root->insert(new TLexemNode(tmp, rest.Chars(i+1, rest.Chars().length() -i -1))) ;
#endif
				tmp.SetChars(i, ch);
			}
		}

	}

#ifdef Windows
	for (i = root->LowerBound(); i < root->LowerBound() + root->GetItemsInContainer(); i++)
	{
		if (!transcribe_as_compound(root->Children(i)))
		{
			delete root->Children(i);
			root->RemoveEntry(i--);
		}
	}
#else
	for (TLexemNode::iterator ii = root->begin() ; ii < root->end() ; ii++) {
		if (!transcribe_as_compound(*ii)) {
			delete(*ii) ;
			root->erase(ii--) ;  } }

#endif

	return (root->is_empty()) ? false : true;
}


////////////////////////////////////////////////////////////////////////////////////////

#if !defined(NPETRA)

bool TLexicon::transcribe_with_PTRA (TLexem &lexem)
{	statistics("with_PTRA (TLexem &lexem = \"" << lexem.Chars() << "\")");

	char *temp = ptra->transcribe(lexem.Chars().c_str());

   if (temp == NULL)
   	return false ;

	lexem.lemma = "PTRA-Transkription";
	lexem.transcription = temp;
	lexem.SetWordClass(NAM);
	CLEAR(temp);
	return true;
}

#endif

