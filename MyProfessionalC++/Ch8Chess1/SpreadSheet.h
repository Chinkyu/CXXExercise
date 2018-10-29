#include "SpreadsheetCell.h"

class Spreadsheet
{
public:
	Spreadsheet(int inWidth, int inHeight);
	void setCellAt(int x, int y, const SpreadsheetCell& cell);
	SpreadsheetCell& getCellAt(int x, int y);
private:
	bool inRange(int val, int upper);
	int mWidth, mHeight;
	SpreadsheetCell** mCells;
};