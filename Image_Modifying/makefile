proj3.exe: chooseFromMenu.o outputMenu.o showImage.o ColorClass.o ColorImageClass.o constants.h insertImage.o secondChoice.o firstChoice.o checkNumValid.o matchColor.o annotateImageWithImage.o annotateImageWithPat.o setObjColor.o PatternClass.o annotateImageWithRec.o RectangleClass.o RowColumnClass.o NonTranspImageClass.o main.o
	g++ chooseFromMenu.o outputMenu.o showImage.o ColorClass.o ColorImageClass.o constants.h insertImage.o secondChoice.o firstChoice.o checkNumValid.o matchColor.o annotateImageWithImage.o annotateImageWithPat.o setObjColor.o PatternClass.o annotateImageWithRec.o RectangleClass.o RowColumnClass.o NonTranspImageClass.o main.o -o proj3.exe

main.o: main.cpp
	g++ -c main.cpp -o main.o

chooseFromMenu.o: chooseFromMenu.cpp chooseFromMenu.h
	g++ -c chooseFromMenu.cpp -o chooseFromMenu.o

outputMenu.o: outputMenu.cpp outputMenu.h
	g++ -c outputMenu.cpp -o outputMenu.o

showImage.o: showImage.cpp showImage.h
	g++ -c showImage.cpp -o showImage.o

ColorClass.o: ColorClass.cpp ColorClass.h
	g++ -c ColorClass.cpp -o ColorClass.o

ColorImageClass.o: ColorImageClass.cpp ColorImageClass.h
	g++ -c ColorImageClass.cpp -o ColorImageClass.o

insertImage.o: insertImage.cpp insertImage.h
	g++ -c insertImage.cpp -o insertImage.o

secondChoice.o: secondChoice.cpp secondChoice.h
	g++ -c secondChoice.cpp -o secondChoice.o

firstChoice.o: firstChoice.cpp firstChoice.h
	g++ -c firstChoice.cpp -o firstChoice.o

checkNumValid.o: checkNumValid.cpp checkNumValid.h
	g++ -c checkNumValid.cpp -o checkNumValid.o

matchColor.o: matchColor.cpp matchColor.h
	g++ -c matchColor.cpp -o matchColor.o

annotateImageWithImage.o: annotateImageWithImage.cpp annotateImageWithImage.h
	g++ -c annotateImageWithImage.cpp -o annotateImageWithImage.o

annotateImageWithPat.o: annotateImageWithPat.cpp annotateImageWithPat.h
	g++ -c annotateImageWithPat.cpp -o annotateImageWithPat.o

setObjColor.o: setObjColor.cpp setObjColor.h
	g++ -c setObjColor.cpp -o setObjColor.o

PatternClass.o: PatternClass.cpp PatternClass.h
	g++ -c PatternClass.cpp -o PatternClass.o

annotateImageWithRec.o: annotateImageWithRec.cpp annotateImageWithRec.h
	g++ -c annotateImageWithRec.cpp -o annotateImageWithRec.o

RectangleClass.o: RectangleClass.cpp RectangleClass.h
	g++ -c RectangleClass.cpp -o RectangleClass.o

RowColumnClass.o: RowColumnClass.cpp RowColumnClass.h
	g++ -c RowColumnClass.cpp -o RowColumnClass.o

NonTranspImageClass.o: NonTranspImageClass.cpp NonTranspImageClass.h
	g++ -c NonTranspImageClass.cpp -o NonTranspImageClass.o

clean:
	rm -rf proj3.exe main.o chooseFromMenu.o outputMenu.o showImage.o ColorClass.o ColorImageClass.o insertImage.o secondChoice.o firstChoice.o checkNumValid.o matchColor.o annotateImageWithImage.o annotateImageWithPat.o setObjColor.o PatternClass.o annotateImageWithRec.o RectangleClass.o RowColumnClass.o NonTranspImageClass.o


