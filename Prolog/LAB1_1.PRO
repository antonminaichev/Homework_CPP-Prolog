Domains
 file = text_input_file
 sentences = string*
Database
 sentence_db(string)
Predicates
 load_sentences
 sentences_into_db(sentences)
 task
 print_sentences(string)
 string_into_sentences(string,sentences)
 string_into_sentences(string,sentences,sentences)
 get_first_sentence(string,string,string)
 is_delimiter(char)
 compare(string, string)
 remove_spaces(string, string)
 Goal load_sentences, task.
Clauses
 load_sentences:-
 	FileName = "/text.txt",
 	existfile(FileName),
 	openread(text_input_file,FileName), !,
 	readdevice(text_input_file),
 	readln(String),
	closefile(text_input_file),
 	string_into_sentences(String, Sentences),
 	retractall(sentence_db(_)),
 	sentences_into_db(Sentences).

 string_into_sentences(String,Sentences):-
 	string_into_sentences(String,[],Sentences).
 string_into_sentences("",Buffer,Buffer):-!.
 string_into_sentences(String,Buffer,Sentences):-
  	get_first_sentence(String,SentenceWithSpaces,StringTail), !,
	remove_spaces(SentenceWithSpaces, Sentence),
  	string_into_sentences(StringTail,[Sentence|Buffer],Sentences).

 get_first_sentence("", "", ""):-!.
 get_first_sentence(String, Sentence, StringTail):-
 	frontchar(String,Char,StringTail),
 	is_delimiter(Char), !,
 	frontchar(Sentence, Char, "").
 get_first_sentence(String, Sentence, Tail):-
 	frontchar(String, Char, StringTail),
 	get_first_sentence(StringTail, TailSentence, Tail),
 	frontchar(Sentence, Char, TailSentence).
 	
 remove_spaces(StringWithSpaces, String):- 
 	frontchar(StringWithSpaces, ' ',StringWithoutSpaces), !,
 	remove_spaces(StringWithoutSpaces, String).
 	remove_spaces(String, String).
 	
 is_delimiter('.'). is_delimiter('!'). is_delimiter('?').

 sentences_into_db([]).
 sentences_into_db([Head|Tail]):-
  	assert(sentence_db(Head)),
  	sentences_into_db(Tail).
 print_sentences(FirstSymbols):-
 	sentence_db(Sentence),
 	compare(Sentence, FirstSymbols),
 	write("Sentence: "),write(Sentence), nl, fail; !.
 compare(Sentence, Symb):- 
 	frontchar(Sentence,Sentence_ch, Rest_sent),
 	frontchar(Symb,Symb_ch,Rest_beg),
 	Sentence_ch=Symb_ch,
 	compare(Rest_sent, Rest_beg).
 compare(Sentence,"").

 task:-
 	makewindow(1,121,15, "Minaichev Anton", 0, 0, 25, 80),
 	storage(A,_,_),
 	write(A), nl,
 	write("Enter the first symbols of the sentence (empty string to exit): "),
 	readln(FirstSymbols),
 	NOT(FirstSymbols = ""), !,
 	print_sentences(FirstSymbols),
 	readchar(_),
 	task;!.
