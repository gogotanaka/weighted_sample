require 'minitest_helper'

class TestWeightedSample < MiniTest::Unit::TestCase
  def test_general
    assert_equal [1, 2, 2, 3, 3, 3], [1, 2, 3].expand { |e| e }
    assert_equal [1, 2, 2, 3, 3, 3], [1, 2, 3].sample { |e| e }
  end
end
