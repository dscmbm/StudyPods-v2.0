package main

import (
	"database/sql"
	"fmt"
	"os"
	"os/exec"

	"github.com/common-nighthawk/go-figure"

	"log"

	_ "github.com/alexbrainman/odbc"
)

var db *sql.DB

func OpenDatabase() error {
	var err error

	db, err = sql.Open("odbc", "DSN=CData MS Access")
	if err != nil {
		return err
	}

	return db.Ping()
}

func Insertdata() {
	var name, fathername string
	var hi, eg, ph, cs, ma, total, per int
	insertdatasql := `insert into student(Name, FatherName, Hindi, English, Physics, ComputerScience, Maths, Total, per) values(?,?,?,?,?,?,?,?,?)`
	fmt.Println("Enter Student Name")
	fmt.Scanln(&name)
	fmt.Println("Enter Student's Father Name")
	fmt.Scanln(&fathername)
	fmt.Println("Enter Marks in Hindi")
	fmt.Scanln(&hi)
	fmt.Println("Enter Marks in English")
	fmt.Scanln(&eg)
	fmt.Println("Enter Marks in Physics")
	fmt.Scanln(&ph)
	fmt.Println("Enter Marks in Computer Science")
	fmt.Scanln(&cs)
	fmt.Println("Enter Marks in Maths")
	fmt.Scanln(&ma)
	total = hi + eg + ph + cs + ma
	per = total / 5
	db.Exec(insertdatasql, name, fathername, hi, eg, ph, cs, ma, total, per)
}

func showdata() {
	var sid int
	var name, fathername string
	var hi, eg, ph, cs, ma, total, per int
	fmt.Println("Enter Your Roll No.")
	fmt.Scanln(&sid)
	sel := `select * from student where ID=?`
	stmt, err := db.Query(sel, sid)
	if err != nil {
		log.Println(err)
		return
	}

	for stmt.Next() {
		err := stmt.Scan(&sid, &name, &fathername, &hi, &eg, &ph, &cs, &ma, &total, &per)
		if err != nil {
			log.Println(err)
		}
	}
	err = stmt.Err()
	if err != nil {
		log.Println(err)
	}
	fmt.Println("|-----------------------------------------|")
	myFigure := figure.NewFigure(" Result   ", "", true)
	myFigure.Print()
	fmt.Println("|-----------------------------------------|")
	fmt.Printf("| Roll No. :- %d                           |\n", sid)
	fmt.Printf("| Student's Name :- %s                |\n", name)
	fmt.Printf("| Father's Name :- %s           |\n", fathername)
	fmt.Println("|-----------------------------------------|")
	fmt.Printf("| Hindi                    |%d            |\n", hi)
	fmt.Printf("| English                  |%d            |\n", eg)
	fmt.Printf("| Physics                  |%d            |\n", ph)
	fmt.Printf("| Computer Science         |%d            |\n", cs)
	fmt.Printf("| Maths                    |%d            |\n", ma)
	fmt.Println("|-----------------------------------------|")
	fmt.Printf("| Total                    |%d           |\n", total)
	fmt.Println("|-----------------------------------------|")
	fmt.Printf("| Per                      |%d            |\n", per)
	fmt.Println("|-----------------------------------------|")

	defer stmt.Close()
}

func init() {
	cmd := exec.Command("cmd", "/c", "cls")
	cmd.Stdout = os.Stdout
	cmd.Run()
	myFigure := figure.NewFigure("School Student Data", "", true)
	myFigure.Print()

}

func main() {
	var i int
	OpenDatabase()
	fmt.Println("Select\n1 to Insert Student Info\n2 to Show Result")
	fmt.Scanln(&i)
	switch i {
	case 1:
		Insertdata()
		main()
	case 2:
		showdata()
		main()
	}
}
