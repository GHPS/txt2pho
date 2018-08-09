
if (wortart == VRB)
	{betonung = 18;
	if (satzposi == 1 || satzposi == 4)
		{betonung = 20;
		if (wa_1p == NEG )
			{betonung = 25;}}
	if (satzposi == 2 || satzposi == 3)
		{betonung = 16;
		if (wa_1f == VRB)
			{betonung = 25;}}}


if (wortart == VEM)
	{betonung = 17;
	if (satzposi == 3 || satzposi == 0)
		{betonung = 13;}}


if (wortart == VES)
	{betonung = 11;
	if (satzposi == 1 || satzposi == 4)
		{betonung = 15;}
	if (satzposi == 2 || satzposi == 3 || satzposi == 0)
		{ if (wa_1f == MOD)
			{betonung = 17;}}}
		

if (wortart == VEW || wortart == VEH)
	{betonung = 15;
	if (satzposi == 3)
		{betonung = 12;}}


if (wortart == TME)
	{betonung = 24;
	if (wa_1p == NOM)
		{betonung = 18;}}
	




if (wortart == QAV)
	{betonung = 17;
	if (satzposi == 1 || satzposi == 2)
		{betonung = 21;}
	if (satzposi == 3 || satzposi == 0)
		{betonung = 14;}
	if (wa_1f == NUM || wa_1f == QAV )
		{betonung = 8;}
	if (wa_1p == QAV )
		{betonung = 17;}
	if (wa_1f == VES || wa_1f == VEW || wa_1f == VEH || wa_1f == 	VRB || wa_1f == VEM)
		{betonung = 20;}}
	

if (wortart == QPV)
	{betonung = 22;
	if (satzposi == 1)
		{betonung = 26;}
	if (satzposi != 1)
		{ if (wa_1f == VES || wa_1f == VEW || wa_1f == VEH || 				wa_1f == VRB || wa_1f == VEM)
			{betonung = 20;}
		if (wa_1p == VES || wa_1p== VEW || wa_1p == VEH || 				wa_1p == VRB || wa_1p == VEM)
			{betonung = 24;}}}


if (wortart == QAN)
	{ betonung = 20;
	if (wa_1p == PRO && wa_1f == NOM)
		{betonung = 17;}}


if (wortart == QPN)
	{betonung = 23;}


if (wortart == NUM)
	{betonung = 23;
	 if (wa_3p != NUM && wa_2p != NUM && wa_1p == NUM && 	wa_1f  == NUM )
		{betonung = 19;}
	if (wa_2p == NUM && wa_1p == NUM && wa_1f == NUM)
		{betonung = 13;}
	 if (wa_3p != NUM  && wa_2p == NUM && wa_1p == NUM && 	wa_1f != NUM)
		{betonung = 26;}}


if (wortart == NOM)
	{betonung = 22;
	if (satzposi == 1 || satzposi == 4)
		{betonung =  25;
		if (wa_1p == QAN)
			{ betonung =  26;}}
	if (wa_1p == ADD)
		{betonung = 24;}}


if (wortart == NAM)
	{ betonung = 23;
	if (satzposi == 1 || satzposi == 4)
		{betonung =  26;
		if (wa_1p == QAN)
			{ betonung =  27;}}
	if (wa_1p == ADD)
		{betonung = 25;}}


if (wortart == ART)
	{ betonung = 5;
	if (satzposi == 1)
		{betonung = 8;}
	if (wa_1f == VRB) 	 //		#nur zur Sicherheit#
		{betonung = 16;}}


if (wortart == PPR)	  //	# Reflexiv- und Personalpronomen#
	{betonung = 7;
	if (satzposi == 1)
		{betonung = 11;}
	if (satzposi == 2 || satzposi == 3)
		{betonung = 4;}
	if (satzposi == 4)
		{betonung = 14;}}


if (wortart == PRO)	  //	#alle anderen Pronomina#
	{betonung = 15;
	if (satzposi == 1)
		{betonung = 19;}
	if (satzposi == 2 || satzposi == 3)
		{betonung = 12;}
	if (satzposi == 4)
		{betonung = 22;}}




if (wortart == ADD)
	{betonung = 6;
	if (wa_1f == ADD)
		{betonung = 8;}
	if (satzposi == 1)
		{betonung = 10;}
	if (wa_1p == ADD)
		{betonung = 3;}}


if (wortart == KNJ)
	{betonung = 11;}

if (wortart == VKN)
	{betonung = 7;}

if (wortart == KKN)
	{betonung = 23;}




if (wortart == SBJ)
	{betonung = 13;}

if (wortart == NEG)
	{betonung = 10;
	if (satzposi == 1)
		{betonung = 20;}
	if (satzposi == 4)
		{betonung = 15;}}


if (wortart == INJ)
	{betonung = 15;
	if (satzposi == 1)
		{betonung = 20;}}


if (wortart == MOD)
	{betonung = 12;
	if (satzposi == 1)
		{betonung = 17;}
	if (wa_1f == NEG)
		{betonung = 20;}}


