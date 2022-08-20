read "src/HelpFunctions.mpl";


knotsVector:=[0,0,0,0,0.5,1,1,1,1];

with(CodeTools);
Test(IntervalIndex(0.25,knotsVector),3);

Test(AllIntevalIndexes(knotsVector),[3,4]);