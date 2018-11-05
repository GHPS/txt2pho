
TXT2PHO - a TTS front end for the German inventories of the MBROLA project.
Version 0.9.0

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
Important since 0.8.2:
Command line options have changed!
.txt2phorc file will be read!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
LICENSE:

This program and object code is being provided to "you", the licensee, by Thomas Portele, the "author", under the following license, which applies to any program, object code or other work which contains a notice placed by the copyright holder saying it may be distributed under the terms of this license. The "program", below, refers to any such program, object code or work.

By obtaining, using and/or copying this program, you agree that you have read, understood, and will comply with these terms and conditions:
Terms and conditions for the distribution of the program

This program may not be sold or incorporated into any product which is sold without prior permission from the author.

When no charge is made, this program may be copied and distributed freely, provided that this notice is copied and distributed with it. Each time you redistribute the program (or any work based on the program), the recipient automatically receives a license from the original licensor to copy or distribute the program subject to these terms and conditions. You may not impose any further restrictions on the recipients' exercise of the rights granted herein. You are not responsible for enforcing compliance by third parties to this License.

If you wish to incorporate the program into other free programs whose distribution conditions are different, write to the author to ask for permission.

If, as a consequence of a court judgment or allegation of patent infringement or for any other reason (not limited to patent issues), conditions are imposed on you (whether by court order, agreement or otherwise) that contradict the conditions of this license, they do not excuse you from the conditions of this license. If you cannot distribute so as to satisfy simultaneously your obligations under this license and any other pertinent obligations, then as a consequence you may not distribute the program at all. For example, if a patent license would not permit royalty-free redistribution of the program by all those who receive copies directly or indirectly through you, then the only way you could satisfy both it and this license would be to refrain entirely from distribution of the program.
Terms and conditions on the use of the program

Permission is granted to use this software for non-commercial, non-military purposes, with and only with the lexicon and prosody files made available by the author from the HADIFIX for MBROLA project (HADIFIXforMBROLA).
Disclaimer

THIS SOFTWARE CARRIES NO WARRANTY, EXPRESSED OR IMPLIED. THE USER ASSUMES ALL RISKS, KNOWN OR UNKNOWN, DIRECT OR INDIRECT, WHICH INVOLVE THIS SOFTWARE IN ANY WAY. IN PARTICULAR, THE AUTHOR DOES NOT TAKE ANY COMMITMENT IN VIEW OF ANY POSSIBLE THIRD PARTY RIGHTS.
GOAL

This software is made public in order to support the MBROLA project with a free German Text-to-Phoneme conversion, which is essentially the linguistic and prosodic part of the synthesis system tpo@ikp.uni-bonn.de). I will supply frequent updates of the lexica as bugfixes.
DISTRIBUTION:

This distribution contains the executables txt2pho and pipefilt, two file sets with prosodic information for male and female voices (*.int, *.dur, *.prt, *.amp), and the lexica (hadifix.sce, hadifix.scf, hadifix.scr), files with missing diphone lists (de1.mdp, and de2.mdp), two sets of parameters for the neural net duration control (kons.par, vokal.par) a few demo files (*.txt) and this file.

It requires the MBROLA synthesizer with at least one German database, obtainable from

http://tcts.fpms.ac.be/synthesis

This program is tested only tentatively - it is likely that certain phoneme combinations are not supported by the current German voices. In this case, let me know, and I will try to fix it.
INSTALLATION AND USAGE:

After the extraction of the file txt2pho.tgz a subdirectory txt2pho_data with all files necessary to run txt2pho is created.

A sample file .txt2phorc is also included - copy it to your home directory and edit it.

txt2pho now has proper command line options. Try "txt2pho -h" for a summary. Sorry, no backward compatibility...

The program
reads text from stdin and writes the MBROLA commands to stdout. In its current version every NEWLINE is treated as a marker for sentence finality. When synthesizing continuous text this will lead to unwanted breaks in an utterance. The program pipefilt should correct this fault in a very simple fashion: it inserts a NEWLINE after every '.:;!?', followed by a whitespace, and changes all other NEWLINEs into blanks. There are of course much better and application-oriented methods for this.

In its current stage txt2pho does not much preprocessing. Abbreviations, numbers, symbols etc. are not handled.

 

IMPORTANT:
A program that allows reading of numbers written by Michael Binder can be obtained from ftp.gwdg.de/pub/linux/misc/text_to_speech/numfilt-0.1.tar.gz

Another program that does text preprocessing can be obtained from Preproc.html

German ä can be entered as ä, "a, or ae (but that's not unambiguous). TeX notation is safe. Is it? I'm not sure about this :-(

The file with missing diphones belongig to the current database must be copied to imppairs.xxx in the txt2pho_data directory prior to the start of txt2pho.
WHAT DOES IT DO, AND HOW:

The conversion from graphemes to phonemes is done using a lexicon with more than 50000 entries and flexion tables. The system tries to find compound words (which does sometimes leads to interesting results). A description of the linguistic processing is given in (Portele & Kraemer, 1995 - ftp://ftp.asl1.ikp.uni-bonn.de/pub/vm41/tpwolf95.ps.gz - in German). During this process word classes are derived which are converted to prominence values (Widera, Portele & Wolters, 1997 - not yet on the Internet). These parameters drive a prominence-based synthesis system (Portele & Heuft, 1996 - ftp://asl1.ikp.uni-bonn.de/pub/vm41/tpspeak2.ps.gz). A decision tree (*.prt) converts the prominence values into prosodic parameters (Heuft & Portele, 1996 - ftp://asl1.ikp.uni-bonn.de/pub/vm41/bhics962.ps.gz). Here, speaker dependent parameters (*.int for f0, *.dur for duration) are used.

From version 0.7.0 the sound durations can be controlled by a number of neural networks. The use of the networks is controlled by a line in the file "hadifix.cfg"
USENET=<X>
with 0=Do not use NN
     1=Use one NN for vowels and one for consonants
     2=Use several NN for different phonemes

From version 0.7.2 a new decision tree for intonation contour generation "newtree.prt" is included which uses a phonological description of German intonation peaks. The use of this tree is controlled by a line in the file "hadifix.cfg"
NEWTREE=<tree_name>

The reduction level can be defaulted by a line in the file "hadifix.cfg"
REDUCTION=<level>
with level 0 to 6. The higher the number, the more symbolic reductions will be simulated.

Form version 0.7.7 the speechrate can be controlled by a line in the file "hadifix.cfg"
SPEECHRATE=<rate>
1.0 is normal, 1.5 is slow, 0.5 is fast

From version 0.8.4 the way internal syllable prominences are computed can be controlled by a line in the file "hadifix.cfg"
PROMCOMP=<X>
with 0=Use Rules
     1=Use CART tree

From version 0.8.7 a comment can be added to the input by {Comment:XXX}, and the output will contain a line
; XXX
MANIPULATIONS:

Manipulations at the lexicon files are not allowed. Manipulations of the decision tree is possible but dangerous. In the files *.dur the first parameter denotes the default speaking rate. In the files *.int pitch height is controlled, and these numbers can be adapted to personal needs.

A number of control sequences can be included (Portele, 1996, - ftp://asl1.ikp.uni-bonn.de/pub/vm41/tpdaga962.ps.gz) in the orthographic input when placed between braces. A space character may not appear in a command. Commands must be separated from other words or commands by a space character. Commands contain a keyword followed by a colon and the command parameters. Among the commands are
Voice

The command value is the name of the inventory to be used from now on. Its files must be in the directory of the current inventory. However, this only changes the prosodic output and has no effect on the MBROLA synthesizer. Possible names are "male" and "female".
Duration

accepts positive and negative values. The speech rate is changed accordingly.
Pitch

accepts positive and negative values in Hz. The average pitch changes accordingly.
Pause

inserts a pause. The command parameter specifies the length in milliseconds.
WordProminence

controls the prominence of the following word and can be set between 0 (not prominent) and 31 (very prominent).
WordRhythm

modifies the rhythm of a word. For each syllable one of the characters _ (not accented), ' (primary accent), ,(secondary accent) must appear in the command parameter string.
Transcription

gives the transcription for the following word. Syllable boundaries must be indicated by a | and the transcription must be in SAMPA . Primary ' and secondary , accent marks can be included after the syllable boundary sign.
BoundaryStrength

determines the number of boundaries between words. The lower this value is, the more boundaries will be inserted. 0 produces a boundary after every word. Default is 2.
Accent

mimics in a very crude way some local varieties of Standard German. Up to now, only Rheinisch is a valid parameter.
Singing

allows the synthesis of a song. For every syllable the length and the value of the pertinent note must be specified. The length may be one of 4 , 8 , 16 , whereby 16 is the shortest. The value can be one of c , cis , d , es , e , f , fis , g , as , a , b , h . If the value is followed by a ' it is assumed to be in the next octave. Length and value are seperated by a comma, notes for different syllable by a semicolon. A command might therefore look like: {Singing:8,f;8,g;4,e}. Multiple singing commands can appear in one utterance.
SetSingingTempo

defines the tempo of the song from now on. Valid parameter values are a number for beats per minute or one of the following strings:
Largo , Larghetto , Adagio , Andante , Alegretto , Allegro , Presto .
SetOctave

defines the heigth of the singing voice. Valid parameters are C , c , c' , c'' , c''' .
UseNet

controls the use of the Neural Networks for duration control. It overrides the values set in the file "hadifix.cfg"
Comment

hands a number of characters over to the output

Examples can be found in the files with the extension .txt in the txt2pho_data directory
PROBLEMS:

    Because txt2pho was made for a more complex inventory than diphones where every phoneme combination is synthesizable the system might demand combinations not in the inventory. In such case a substitute is provided, however, the speech quality might be degraded,
    Some reductions inherent in the original inventory cannot be synthesized adequately with the diphone databases, and the speech may sometimes sound overaticulated (e.g. non-syllablic vowels in "Bosnien" or syllabic consonants in "haben").
    A few words are wrongly accented
    A number of irrelevant error messages may appear in the log file

 
HISTORY:
22.11.1997 	French nasal vowels and English /EI/ remapped
26.11.1997 	New version of the lexicon
28.11.1997 	Fix for the "missing diphone" problem
13.12.1997 	Command line argument for data directory / new version of the lexicon
3.1.1998 	new lexicon version
6.1.1998
  	bug in syllable border placement caused wrong accentuation - fixed different boundary strengths can be adjusted, new default value new version of the lexicon
22.1.1998 	bug in preprocessing, new version of the lexicon
24.2.1998 	new version of the lexicon, correction in spelling routine
6.3.1998 	new version of the lexicon
4.5.1998 	minor revisions
3.7.1998 	duration network included, 'R@R' error fixed, new version of the lexicon
4.7.1998 	severe bug in compound analysis fixed
14.7.1998 	new intonation model, reduction level externalized
15.7.1998 	version number in program
14.8.1998 	fixed all storage leaks, tested by processing 1,2M words
18.8.1998 	switched to standard transcription SAMPA, standard input ANSI
30.8.1998 	fixed bug in rule transcription, new version of lexicon
10.9.1998 	fixed a bug in duration network, enabled SPEECHRATE in config file
15.9.1998 	included decision tree duration control, fixed bug in word prosody module
20.9.1998 	bug in lexicon lookup fixed, new lexicon
21.11.1998 	some bugs, new lexicon, better number support
8.1.1999 	a large number of bugfixes, new lexicon
24.1.1999 	other bugfixes, proper command line support, CART prominence computation
27.1.1999 	rc file included
12.3.1999 	several fixes, small changes, {Comment}-feature
19.5.1999 	some minor fixes
1.6.1999 	fixed some severe errors
Acknowledgements:

I got a lot of help from a number of people:

Barbara Heuft
Horst Meyer
Florian Höfer
Monika Rauth
Gerit Sonntag
Jürgen Krämer
Stefan Breuer
Jörg Bröggelwirth
Felicitas Haas
Volker Strom
Karlheiz Stöber
Anja Elsner
Wolfgang Hess
Dieter Stock
Dietmar Lance
Bernhard Schröder
...

and my family (as usual).

Thomas Portele
email: thomas@portele.de
