/*

	ffuzzy++ : C++ implementation of fast fuzzy hasing

	tests/cases/compatibility/small/digest_comparison_identical.hpp
	Tests for identical digest comparison (compare with version 2.12)

	Copyright (C) 2017 Tsukasa OI <floss_ssdeep@irq.a4lg.com>


	Permission to use, copy, modify, and/or distribute this software for
	any purpose with or without fee is hereby granted, provided that the
	above copyright notice and this permission notice appear in all copies.

	THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
	WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
	MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
	ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
	WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
	ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
	OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

*/
#ifndef FFUZZYPP_TESTCASES_COMPATIBILITY_SMALL_DIGEST_COMPARISON_IDENTICAL_HPP
#define FFUZZYPP_TESTCASES_COMPATIBILITY_SMALL_DIGEST_COMPARISON_IDENTICAL_HPP

#include <string>


// Data used in tests are retrieved partially from ssdeep and others from ssdeep 2.9, x86_64
// (because ssdeep 2.12 currently has a critical bug regarding identical digest comparison).

TEST(DigestComparisonIdenticalTests, NormalizationComparisonTest)
{
	EXPECT_EQ(100, digest_comparison<>::compare("3:AAAAAAA:", "3:AAAAAAAAAAAAAA:"));
	EXPECT_EQ(100, digest_comparison<>::compare("3::AAAAAAA", "3::AAAAAAAAAAAAAA"));
	EXPECT_EQ(100, digest_comparison<>::compare("3:AAAAAABCCCCCC:", "3:AAABCCC:"));
	EXPECT_EQ(  7, digest_comparison<>::compare("3:AAAAAABCCCCCC:D", "3:AAABCCC:E"));
	EXPECT_EQ(100, digest_comparison<>::compare("3::AAAAAABCCCCCC", "3::AAABCCC"));
	EXPECT_EQ( 14, digest_comparison<>::compare("3:D:AAAAAABCCCCCC", "3:E:AAABCCC"));
	EXPECT_EQ(100, digest_comparison<>::compare(
		"3:aaaaaaaabbbbbbbbccccccccddddddddeeeeeeeeffffffffgggggggghhhhhhhh01234567:",
		"3:aaabbbcccdddeeefffggghhh01234567:"
	));
}

#endif
