#include "gtest/gtest.h"
#include "../Builders/EndTransactionBuilder.h"

TEST(EndTransaction, TEST_END_TRANSACTION)
{
	string query = EndTransactionBuilder().
			End("MyTransaction").
			Build();

	ASSERT_EQ("END MyTransaction;", query);
}
