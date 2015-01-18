require 'minitest_helper'

class TestWeightedSample < MiniTest::Unit::TestCase
  def test_general
    assert_equal 1, [1, 2, 3].sample { |e| e }
  end
end
