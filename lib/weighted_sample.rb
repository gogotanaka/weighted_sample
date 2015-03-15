require "weighted_sample/weighted_sample"

class Array
  alias original_sample sample
  def sample(&blk)
    expand(&blk).original_sample
  end
end
