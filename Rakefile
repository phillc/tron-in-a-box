class Bot
  def compile
    puts "#{self.name} has nothing to compile"
  end
end

module StarterPackage
  def self.all
    [Clojure, Cpp, Haskell].map(&:new)
  end

  class Base < Bot
    def name
      self.class.name.split("::").last
    end

    def description
      "#{name} starter package"
    end

    protected

    def package_path
      File.join(File.dirname(__FILE__), "starter_packages", "clojure")
    end
  end

  class Clojure < Base
    def run_command
      "clj #{package_path}/MyTronBot.clj"
    end
  end

  class Cpp < Base
  end

  class Haskell < Base
  end
end

class ExampleBot < Bot
  def self.all
    Dir[File.dirname(__FILE__) + "/example_bots/*.jar"].map{|filename| self.new filename}
  end

  def initialize filename
    @filename = filename
  end

  def name
    File.basename(@filename, ".jar")
  end

  def description
    "#{name} example bot"
  end

  def run_command
    "java -jar #{@filename}"
  end
end

module Engine
  def self.all
    [Java, Python].map(&:new)
  end

  class Base
    def name
      self.class.name.split("::").last
    end

    protected

    def maps
      Dir[File.dirname(__FILE__) + "/maps/*"]
    end

    def get_random_map
      maps.sample
    end
  end

  class Java < Base
    def matchup bot1, bot2
      map = get_random_map
      command = %Q{java -jar engine/java/Tron.jar #{map} "#{bot1.run_command}" "#{bot1.run_command}" 0}
      puts command
      Kernel.exec command
    end
  end

  class Python < Base
    def matchup bot1, bot2
      map = get_random_map
      command = %Q{./engine/python/round.py -vi "#{bot1.run_command}" "#{bot2.run_command}" --board-file=#{map}}
      puts command
      Kernel.exec command
    end
  end
end

Engine.all.each do |engine|
  namespace engine.name.downcase do
    StarterPackage.all.product(ExampleBot.all).each do |bots|
      desc "using the #{engine.name} engine to play #{bots.map(&:description).join(" vs ")}"
      task bots.map(&:name).map(&:downcase).join(":") do
        bots.each(&:compile)

        engine.matchup *bots
      end
    end
  end
end

