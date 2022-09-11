from io import TextIOWrapper
import git_of_theseus
import os

os.chdir("..")

cur_dir: str = os.getcwd()

git_of_theseus.analyze(cur_dir)

git_of_theseus.stack_plot("cohorts.json")


