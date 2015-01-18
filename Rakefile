require "bundler/gem_tasks"
require "rake/testtask"

Rake::TestTask.new(:test) do |t|
  t.libs << "test"
end

require "rake/extensiontask"

Rake::ExtensionTask.new("weighted_sample") do |ext|
  ext.lib_dir = "lib/weighted_sample"
end

desc "Run test with compile weighted_sample"
task test_with_compile: [:compile, :test]

task default:  :test_with_compile
