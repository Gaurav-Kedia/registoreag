package com.gaurav.registoreag;

import android.os.Bundle;
import android.support.annotation.NonNull;
import android.support.design.widget.BottomNavigationView;
import android.support.v7.app.AppCompatActivity;
import android.text.TextUtils;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import com.firebase.client.Firebase;
import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;

public class MainActivity extends AppCompatActivity {

    private TextView mTextMessage;
    EditText firstname, lastname, emailE, passwordE, rollnumner;
    String firstnm;
    String lastnm;
    int roll;
    Button btn;

    //FirebaseDatabase database = FirebaseDatabase.getInstance();
    Firebase mfire;

    private BottomNavigationView.OnNavigationItemSelectedListener mOnNavigationItemSelectedListener
            = new BottomNavigationView.OnNavigationItemSelectedListener() {

        @Override
        public boolean onNavigationItemSelected(@NonNull MenuItem item) {
            switch (item.getItemId()) {
                case R.id.navigation_home:
                    mTextMessage.setText(R.string.title_home);
                    return true;
                case R.id.navigation_dashboard:
                    mTextMessage.setText(R.string.title_dashboard);
                    return true;
                case R.id.navigation_notifications:
                    mTextMessage.setText(R.string.title_notifications);
                    return true;
            }
            return false;
        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Firebase.setAndroidContext(this);

        mTextMessage = (TextView) findViewById(R.id.message);
        BottomNavigationView navigation = (BottomNavigationView) findViewById(R.id.navigation);
        navigation.setOnNavigationItemSelectedListener(mOnNavigationItemSelectedListener);

        firstname = (EditText) findViewById(R.id.First);
        lastname = (EditText) findViewById(R.id.Last);
        emailE = (EditText) findViewById(R.id.email);
        passwordE = (EditText) findViewById(R.id.email);
        rollnumner = (EditText) findViewById(R.id.rollnum);

        btn = (Button) findViewById(R.id.buttonRegister);
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                registeruser();
            }
        });

    }
    private void registeruser(){
        String email = emailE.getText().toString().trim();
        final String password = passwordE.getText().toString().trim();
        String firstnm = firstname.getText().toString().trim();
        String lastnm = lastname.getText().toString().trim();

        if(TextUtils.isEmpty(email)){
            //email is empty
            Toast.makeText(this, "Please enter your email", Toast.LENGTH_SHORT).show();
            return;
        }
        if(TextUtils.isEmpty(password)){
            //password is empty
            Toast.makeText(this, "Please enter your password", Toast.LENGTH_SHORT).show();
            return;
        }
        if((mTextMessage.getText()).equals("Teacher")) {
            mfire = new Firebase("https://registorage-6b447.firebaseio.com/Teacher/" + firstnm);
        }
        else if ((mTextMessage.getText()).equals("Student")){
            mfire = new Firebase("https://registorage-6b447.firebaseio.com/Student/" + firstnm);
            roll = Integer.parseInt(rollnumner.getText().toString());
            Firebase rolll = mfire.child("Roll no");
            rolll.setValue(roll);
        }
        else {
            mfire = new Firebase("https://registorage-6b447.firebaseio.com/Parent/" + firstnm);
        }
         //user successfully registered
        Firebase emailID = mfire.child("email");
        Firebase passw = mfire.child("Password");
        Firebase namef = mfire.child("name");
        Firebase namel = mfire.child("lasr name");
        emailID.setValue(email);
        passw.setValue(password);
        namef.setValue(firstnm);
        namel.setValue(lastnm);
        Toast.makeText(MainActivity.this, "Registered successfully", Toast.LENGTH_SHORT).show();

    }

}
