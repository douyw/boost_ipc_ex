require 'yaml'
require 'uri'

namespace :cog do

  desc "gen .pro files"
  task :pro do
    cmds = []
    cmds << "python -m cogapp -r boost_ipc_ex.pro"
    sh cmds * "\n"
  end

end
