#include "UnitTests/TestAlter.h"
#include "UnitTests/TestBeginTransaction.h"
#include "UnitTests/TestCommit.h"
#include "UnitTests/TestCreateIndex.h"
#include "UnitTests/TestCreateTable.h"
#include "UnitTests/TestDelete.h"
#include "UnitTests/TestDropIndex.h"
#include "UnitTests/TestDropTable.h"
#include "UnitTests/TestDropTrigger.h"
#include "UnitTests/TestDropView.h"
#include "UnitTests/TestEndTransaction.h"
#include "UnitTests/TestInsert.h"
#include "UnitTests/TestPragma.h"
#include "UnitTests/TestRollbackTransaction.h"
#include "UnitTests/TestSelect.h"
#include "UnitTests/TestUpdate.h"

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

