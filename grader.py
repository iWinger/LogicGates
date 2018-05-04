#!/usr/bin/python
import autograde
import os, os.path

assignment_name = 'PA4'
release='1'

class ECFileTests(autograde.FileTests):
    def make_test(self, prog, arg, ref):
        return self.Test(
            cmd=[prog, '-h', arg],
            input_file=arg,
            ref_file=ref,
            max_output=self.max_output)

max_out = 50*1024*1024

assignment = autograde.Project('truthtable',
    autograde.FileTests(name='1', id='1.1', weight=2.5, max_output=max_out),
    autograde.StdinFileTests(name='1', id='1.2', weight=2.5, max_output=max_out),
    autograde.FileTests(name='2', id='2.1', weight=2.5),
    autograde.StdinFileTests(name='2', id='2.2', weight=2.5),
    ECFileTests(name='3', id='3', weight=1, category=autograde.EXTRA, max_output=max_out),
)



if __name__ == '__main__':
    autograde.set_asan_symbolizer()
    autograde.main(assignment_name, assignment, release)
