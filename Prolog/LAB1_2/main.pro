% Copyright
implement main
    open core, console

class facts - signs
    pain : (string What).
    tempreature : (integer Value).
    color : (string What, string Color).
    symptom : (string Name).
    examination : (string Name).

class predicates
    loadDB : (string FileName).
    check_ksd : () multi.
    check_examinations : () nondeterm.
    check_symptoms : () multi.
    inputExamination : () procedure.
    inputPainSymptom : () procedure.
    inputChangeColorSymptom : () procedure.
    inputSigns : () procedure.
    inputSymptom : () procedure.
    inputTempreature : () procedure.
    menu : () procedure.
    operation : (integer Num) multi.
    writeAll : () failure.
clauses
    run() :-
        init(),
        menu(), succeed().

    menu () :-
        std::repeat(),
            clearOutput(),
            writef("Минайчев Антон ИУ6-11М Вариант 13\n"),
            writef("Программа диагностирования МКБ\n"
                    "1: Ввод из файла\n"
                    "2: Ввод через командную строку\n"
                    "3: Проверить диагноз\n"
                    "4: Выход\n\n"),
            not(writeAll),
            writef("Введите номер операции: "),
            Operation = read(),
            operation(Operation),
            Operation = 4,
            !, succeed().
        menu().
    % Загрузка фактов из базы данных
    loadDB(FileName) :- if not (file::existFile(FileName)) then
            writef("Файл не найден!"), nl
        else
            retractAll(symptom(_)),  retractAll(pain(_)),  retractAll(color(_,_)),  retractAll(examination(_)),
            try
                file::consult(FileName, signs)
            catch Error do
                stdio::writef("Error %! Loading database from file % was failured\n", Error, FileName), nl
            end try, writef("Файл успешно считан") end if.
        % Проверка МКБ  по результатам обследований
        check_ksd() :-
            check_examinations(),
            writef("У вас МКБ по результатам обследований").
        % Проверка МКБ по симптомам
        check_ksd() :-
            check_symptoms().
        % Провекра фактов наличия обследования
        check_examinations() :-
            examination("УЗИ"); examination("КТ"); examination("МРТ").
        % Провекра наличия всех симптомов МКБ
        check_symptoms() :-
            if pain('таз') or pain('почки') then succeed() end if, pain('мочеиспускание'),
            symptom('частое мочеиспускание'), symptom('слабость'), symptom('недомогание'), color('моча', C),
            if C = 'желтая' then fail else succeed() end if,
            tempreature(T),
            if T >= 37 then succeed() else fail end if,
            writef("У вас все симптомы МКБ, нужны обследования"),!, _ = readLine().
        % Провекра наличия некоторх симптомов МКБ
        check_symptoms() :-
            if
                pain('таз'); pain('мочеиспускание'); pain('мочеиспускание'); symptom('частое мочеиспускание');
                color('моча', C), if C = 'желтый' then fail else succeed() end if
            then writef("У вас некоторые симптомы МКБ, но нельзя точно поставить диагноз"),!, _ = readLine() end if.
        % Проверка наличия симптомов
        check_symptoms() :-
            if symptom(_); pain(_); tempreature(T),
            if T >= 37 then succeed() else fail end if
            then writef("У вас симптомы заболевания, берегите себя!"),!, _ = readLine() end if.
        inputSigns() :- std::repeat,
            clearOutput(),
            writef("Ввод признаков заболевания\n"
                    "1: Ввести симптом\n"
                    "2: Ввести обследование\n"
                    "3: Ввести болевой симптом\n"
                    "4: Ввести симтом с изменением цвета\n"
                    "5: Ввести температуру\n"
                    "6: Удалить всё\n"
                    "7: Выход\n\n"),
            not(writeAll),
            writef("Выберите операцию: "),
            Num = read(),
            clearInput(),
            if Num = 1 then inputSymptom()
            elseif Num = 2 then inputExamination()
            elseif Num = 3 then inputPainSymptom()
            elseif Num = 4 then inputChangeColorSymptom()
            elseif Num = 5 then inputTempreature
            elseif Num = 6 then retractAll(symptom(_)),  retractAll(pain(_)),  retractAll(color(_,_)),  retractAll(examination(_))
            end if,
            Num = 7, !, succeed().
        inputSigns().

        inputSymptom() :- writef("Опишите симтомы\n"), writef("Введите синдром: "), S = readLine(), assert(symptom(S)).

        inputExamination() :- writef("Введите обследования МКБ\n"), writef("Введите обследование: "), S = readLine(), assert(examination(S)).

        inputPainSymptom() :- writef("Укажите часть тела или действие во время которого вы используете боль\n"), writef("Введите болевой симптом: "), S = readLine(), assert(pain(S)).

        inputChangeColorSymptom() :- writef("Укажите что изменило цвет: "), W = readLine(),
                                                       writef("Укажите какой цвет стал: "), C = readLine(), assert(color(W, C)).

        inputTempreature() :- writef("Укажите температуру тела: "), T = read(), assert(tempreature(T)).
        % Выбор операций в главном меню
        operation(Num) :- clearOutput(), clearInput(), !,
            if Num = 1 then
                FileName = readLine(),
                loadDB(FileName),
                _ = readLine()
            elseif Num = 2 then
                inputSigns()
            elseif Num = 3 then
                !, check_ksd()
            elseif Num = 4 then
                writef("Выход...")
            else
                writef("Неверная операция"),
                _ = readLine()
            end if.
        % Вывод введенных фактов
        writeAll() :-
            writef("Текущие факты:"), nl,
            pain(S), writef("Боль в  "), writef(S), nl, fail;
            tempreature(I), writef("Температура: "), write(I), writef(" градусов цельсия"), nl, fail;
            color(W, C), writef("Цвет "), writef(W), writef(C), nl, fail;
            symptom(S), writef("Симптом: "), writef(S), nl, fail;
            examination(S), writef("Обследование: "), writef(S), nl, fail.
        end implement main

        goal console::runUtf8(main::run).


